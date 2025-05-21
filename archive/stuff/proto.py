from lark import Lark, Token, Transformer, Tree, Visitor
from pathlib import Path
from typing import Literal, NamedTuple
import sys
import z3


############################################################
##                        GRAMMAR                         ##
############################################################
# TODO: add support for subranges from variables, not just whole register.
#       (e.g., in coverpoint definition)
# TODO: add full support for expressions
#       https://www.thevtool.com/operator-precedence-and-potential-problems/

GRAMMAR = """
    ?start: covergroup

    covergroup: covergroup_begin content covergroup_end
    ?covergroup_begin: "covergroup" IDENT ";"
    ?covergroup_end: "endgroup" [":" IDENT]

    content: [ coverpoint ]*

    coverpoint: [IDENT ":"] "coverpoint" IDENT (bins | ";")
    bins: "{" bin+ "}"
    bin: BIN_TYPE IDENT [ bin_array ] "=" bin_content ";"   -> bin
    BIN_TYPE: "bins" | "illegal_bins" | "ignore_bins"
    bin_array: "[" [ expr ] "]"                             -> bin_index
    bin_content: DEFAULT                                    -> bin_default
               | "{" range [", " range]* "}"                -> bin_array
               | range                                      -> bin_range
    DEFAULT.2: "default"

    range: expr                     -> range_e
         | "[" expr ":" expr "]"    -> range_e_e
         | "[" END  ":" expr "]"    -> range_t_e
         | "[" expr ":" END  "]"    -> range_e_t
    END.2: "$"

    ?expr: logic
    ?logic: comp
          | logic "&&" comp     -> e_and
          | logic "||" comp     -> e_or
    ?comp: shifts
         | comp "==" shifts     -> e_eq
         | comp "!=" shifts     -> e_neq
         | comp "<=" shifts     -> e_leq
         | comp ">=" shifts     -> e_geq
         | comp "<" shifts      -> e_le
         | comp ">" shifts      -> e_ge
    ?shifts: add_sub
           | shifts ">>" add_sub    -> e_rshift
           | shifts "<<" add_sub    -> e_lshift
    ?add_sub: term
            | add_sub "+" term  -> e_add
            | add_sub "-" term  -> e_sub
    ?term: factor
         | term "*" factor  -> e_mul
         | term "/" factor  -> e_div
         | term "%" factor  -> e_mod
    ?factor: atom
           | "!" factor     -> e_log_neg
           | "~" factor     -> e_bit_neg
           | "-" factor     -> e_num_neg
           | "(" expr ")"   -> e_paranthisis
    ?atom: NUMBER           -> e_num
         | IDENT            -> e_var

    %import common.CNAME -> IDENT
    %import common.NEWLINE
    %import common.NUMBER
    %import common.WS_INLINE

    %ignore WS_INLINE
    %ignore NEWLINE
"""

############################################################
##                     PARSED TYPES                      ##
############################################################
# TODO: Equality should be completly reworked, it is not correct

def is_eq(expr1: z3.ExprRef, expr2: z3.ExprRef) -> bool:
    solver = z3.Solver()
    solver.add(expr1 != expr2)
    return solver.check() == z3.unsat


class Interval(NamedTuple):
    start: z3.ExprRef | Literal['$']
    end: z3.ExprRef | Literal['$']

    def __str__(self) -> str:
        return f'[{self.start}:{self.end}]'

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Interval):
            return False

        if isinstance(self.start, str) != isinstance(other.start, str):
            return False

        if isinstance(self.end, str) != isinstance(other.end, str):
            return False

        for x, y in zip((self.start, self.end), (other.start, other.end)):
            if (isinstance(x, z3.ExprRef)
                and isinstance(y, z3.ExprRef)
                and not is_eq(x, y)):
                return False

        return True


class Bins(NamedTuple):
    category: Literal['normal', 'ignore', 'illegal']
    name: str
    indices: list[z3.ExprRef] | None
    bins: list[Interval | z3.ExprRef] | Literal['default']

    def __str__(self) -> str:
        return (f'Bin({self.category}, {self.name}{self.indices or ""},'
                f'{self.bins})')

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Bins):
            return False

        if self.category != other.category:
            return False

        if (self.indices is None) != (other.indices is None):
            return False

        foo = lambda x: len(x) if isinstance(x, list) else -1
        if foo(self.indices) != foo(other.indices):
            return False

        if (foo(self.indices) == 1) and (foo(other.indices) == 1):
            assert isinstance(self.indices, list)
            assert isinstance(other.indices, list)
            if not is_eq(self.indices[0], other.indices[0]):
                return False

        if (self.bins == 'default') != (other.bins == 'default'):
            return False

        if isinstance(self.bins, list) and isinstance(other.bins, list):
            s_iter = iter(self.bins)
            o_iter = iter(other.bins)
            s_curr = next(s_iter, None)
            o_curr = next(o_iter, None)
            s_idx = 0
            o_idx = 0

            while True:
                if (s_curr is None) != (o_curr is None):
                    return False

                if (s_curr is None) and (o_curr is None):
                    break

                if isinstance(s_curr, Interval) and isinstance(o_curr, Interval):
                    if isinstance(s_curr.start, str) or isinstance(s_curr.end, str):
                        print('[Error] Unsupported bin comparision ($).')
                        return False

                    if isinstance(o_curr.start, str) or isinstance(o_curr.end, str):
                        print('[Error] Unsupported bin comparision ($).')
                        return False

                    if not is_eq(o_curr.start + z3.IntVal(o_idx),
                                 s_curr.start + z3.IntVal(s_idx)):
                        return False

                    s_idx += 1
                    if is_eq(s_curr.start + z3.IntVal(s_idx), s_curr.end + 1):
                        s_curr = next(s_iter, None)
                        s_idx = 0

                    o_idx += 1
                    if is_eq(o_curr.start + z3.IntVal(o_idx), o_curr.end + 1):
                        o_curr = next(o_iter, None)
                        o_idx = 0

                if isinstance(s_curr, Interval) and isinstance(o_curr, z3.ExprRef):
                    if isinstance(s_curr.start, str) or isinstance(s_curr.end, str):
                        print('[Error] Unsupported bin comparision ($).')
                        return False

                    if not is_eq(o_curr, s_curr.start + z3.IntVal(s_idx)):
                        return False

                    s_idx += 1
                    if is_eq(s_curr.start + z3.IntVal(s_idx), s_curr.end + 1):
                        s_curr = next(s_iter, None)
                        s_idx = 0
                    o_curr = next(o_iter, None)

                if isinstance(s_curr, z3.ExprRef) and isinstance(o_curr, Interval):
                    if isinstance(o_curr.start, str) or isinstance(o_curr.end, str):
                        print('[Error] Unsupported bin comparision ($).')
                        return False

                    if not is_eq(s_curr, o_curr.start + z3.IntVal(o_idx)):
                        return False

                    o_idx += 1
                    if is_eq(o_curr.start + z3.IntVal(o_idx), o_curr.end + 1):
                        o_curr = next(o_iter, None)
                        o_idx = 0
                    s_curr = next(s_iter, None)

                if isinstance(s_curr, z3.ExprRef) and isinstance(o_curr, z3.ExprRef):
                    if not is_eq(s_curr, o_curr):
                        return False

                    s_curr = next(s_iter, None)
                    o_curr = next(o_iter, None)

        return True


class Coverpoint(NamedTuple):
    name: str | None
    target: str
    bins: list[Bins]

    def __str__(self) -> str:
        return ((f'{self.name}: ' if self.name else '')
                + f'coverpoint {self.target}'
                + ('\n\t\t' if len(self.bins) > 0 else '')
                + '\n\t\t'.join(map(str, self.bins)))

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Coverpoint):
            return False

        if self.target != other.target:
            return False

        if len(self.bins) != len(other.bins):
            return False

        if any(not x == y for x, y in zip(self.bins, other.bins)):
            return False

        return True


class Covergroup(NamedTuple):
    name: str
    coverpoints: list[Coverpoint]

    def __str__(self) -> str:
        return (f'covergroup {self.name}\n\t'
                + '\n\t'.join(map(str, self.coverpoints)))

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Covergroup):
            return False

        if len(self.coverpoints) != len(other.coverpoints):
            return False

        if any(not x == y for x, y in zip(self.coverpoints, other.coverpoints)):
            return False

        return True


############################################################
##                      VALIDATORS                        ##
############################################################

class CheckIdentifiers(Visitor):
    def covergroup(self, tree: Tree) -> None:
        names = [x.value for x in tree.children
                 if isinstance(x, Token) and x.type == 'IDENT']
        match len(names):
            case 1:
                pass
            case 2:
                assert names[0] == names[1], 'Covergroup names does not match.'
            case _:
                assert False, 'Uh oh, something is wrong.'


############################################################
##                     TRANSFORMERS                       ##
############################################################

class Optimus(Transformer):
    ########################################################
    ##              EVALUATE COVERGROUPS                  ##
    ########################################################
    def covergroup(self, tree: Tree) -> Covergroup:
        assert isinstance(tree, list) and len(tree) == 3
        return Covergroup(name=tree[0].value,
                          coverpoints=tree[1].children)

    ########################################################
    ##              EVALUATE COVERPOINTS                  ##
    ########################################################
    def coverpoint(self, tree: Tree) -> Coverpoint:
        assert isinstance(tree, list) and len(tree) in (2, 3)
        name = None if tree[0] is None else tree[0].value
        target = tree[1].value
        bins = tree[2].children if len(tree) == 3 else []
        return Coverpoint(name=name,
                          target=target,
                          bins=bins)

    ########################################################
    ##                  EVALUATE BINS                     ##
    ########################################################
    def bin(self, tree: Tree) -> Bins:
        assert isinstance(tree, list) and len(tree) == 4
        category = {
            'bins': 'normal',
            'ignore_bins': 'illegal',
            'illegal_bins': 'ignore'}.get(tree[0].value, None)
        assert category is not None, 'Missing bin type'
        assert category in ('normal', 'illegal', 'ignore'), 'Wrong bin type.'
        return Bins(category=category,
                    name=tree[1].value,
                    indices=tree[2],
                    bins=tree[3])

    def bin_index(self, tree: Tree) -> list[z3.ExprRef]:
        if tree == [None]:
            return []
        if isinstance(tree, list):
            return tree
        assert False

    def bin_range(self, tree: Tree) -> list[Interval | z3.ExprRef]:
        assert isinstance(tree, list) and len(tree) == 1
        return [tree[0]]

    def bin_array(self, tree: Tree) -> list[Interval | z3.ExprRef]:
        assert isinstance(tree, list) and len(tree) >= 1
        return list(filter(lambda x: x is not None, tree))

    def bin_default(self, tree: Tree) -> Literal['default']:
        assert isinstance(tree, list) and len(tree) == 1
        return 'default'

    ########################################################
    ##                 EVALUATE RANGES                    ##
    ########################################################
    def range_e(self, tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 1
        return tree[0]

    def range_e_e(self, tree) -> Interval:
        assert isinstance(tree, list) and len(tree) == 2
        return Interval(start=tree[0],
                        end=tree[1])

    def range_t_e(self, tree) -> Interval:
        assert isinstance(tree, list) and len(tree) == 2
        return Interval(start='$',
                        end=tree[1])

    def range_e_t(self, tree) -> Interval:
        assert isinstance(tree, list) and len(tree) == 2
        return Interval(start='$',
                        end='$')

    ########################################################
    ##               EVALUATE EXPRESSIONS                 ##
    ########################################################
    def e_and(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] and tree[1]

    def e_or(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] or tree[1]

    def e_eq(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] == tree[1]

    def e_neq(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] != tree[1]

    def e_leq(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] <= tree[1]

    def e_geq(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] >= tree[1]

    def e_le(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] < tree[1]

    def e_ge(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] > tree[1]

    def e_rshift(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] >> tree[1]

    def e_lshift(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] << tree[1]

    def e_add(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] + tree[1]

    def e_sub(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] - tree[1]

    def e_mul(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] * tree[1]

    def e_div(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] / tree[1]

    def e_mod(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 2
        return tree[0] % tree[1]

    def e_log_neg(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 1
        return tree[0] == 0

    def e_bit_neg(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 1
        return ~tree[0]

    def e_num_neg(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 1
        return -tree[0]

    def e_paranthisis(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 1
        return tree[0]

    def e_num(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 1
        return z3.IntVal(int(tree[0].value))

    def e_var(self, tree: Tree) -> z3.ExprRef:
        assert isinstance(tree, list) and len(tree) == 1
        return z3.Int(tree[0].value)


############################################################
##                       PLAYGROUND                       ##
############################################################

PARSER = Lark(GRAMMAR)


def load(path: Path) -> Covergroup:
    code = Path(path).read_text()
    print(f'Code ({path}):')
    for i, line in enumerate(code.splitlines()):
        print(f'{i+1:-4} | {line}')
    print('--------------------------------------------------')

    tree = PARSER.parse(code)
    CheckIdentifiers().visit(tree)
    return Optimus().transform(tree)


def main():
    path1, path2 = map(Path, sys.argv[1:3])
    try:
        print('Are code equals?', ('no', 'yes')[int(load(path1) == load(path2))])
    except Exception as e:
        print('Error:', e)


if __name__ == '__main__':
    main()
