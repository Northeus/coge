from lark import Lark, Token, Tree, Visitor
from pathlib import Path
import sys


# WIP: Covergroup with simple bins
GRAMMAR = """
    ?start: covergroup

    covergroup: covergroup_begin content covergroup_end
    ?covergroup_begin: "covergroup" IDENT ";"
    ?covergroup_end: "endgroup" [":" IDENT]

    content: [ coverpoint ]*

    coverpoint: [IDENT ":"] "coverpoint" IDENT (bins | ";")
    bins: "{" bin+ "}"
    bin: bin_type IDENT [ bin_array ] "=" bin_content ";"
    ?bin_type: "bins" | "illegal_bins" | "ignore_bins"
    bin_array: "[" [ expr ] "]"
    bin_content: range
               | "{" range [", " range]* "}"

    range: expr
         | "[" expr ":" expr "]"
         | "[" "$"  ":" expr "]"
         | "[" expr ":" "$"  "]"

    ?expr: term
         | expr "+" term
         | expr "-" term
    ?term: factor
         | term "*" factor
         | term "/" factor
         | term "%" factor
    ?factor: atom
           | "!" factor
           | "-" factor
           | "(" expr ")"
    ?atom: NUMBER | IDENT

    %import common.CNAME -> IDENT
    %import common.NEWLINE
    %import common.NUMBER
    %import common.WS_INLINE

    %ignore WS_INLINE
    %ignore NEWLINE
"""


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


def main():
    parser = Lark(GRAMMAR)

    try:
        code = Path(sys.argv[1]).read_text()
        print('Code:')
        for i, line in enumerate(code.splitlines()):
            print(f'{i+1:-4} | {line}')
        print('--------------------------------------------------')

        result = parser.parse(code)
        CheckIdentifiers().visit(result)
        print(result.pretty())
    except Exception as e:
        print('Error:', e)


if __name__ == '__main__':
    main()
