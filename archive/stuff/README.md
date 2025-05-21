# CoGe
Functional coverage generation using LLMs.

## Notes
 - We will ignore covergroup extensions and real values for now.
 - Furthermore, we ignore wildcards and maybe some cross things.
 - And most importantly, we ignore functions inside cross ffs...
 - From options, we use just the at_least option.

## Requirements
 - Python3.13

---

## Examples
Simple covergroup with sampling and cross:
```sv
covergroup g1 @(posedge clk)  // Clocking is optional.
    c: coverpoint color;      // Coverpoint with implicit bins and name c.
    AxC: cross regA, c;       // Implicit declared coverpoints for regA.
endgroup : g1                 // End with optional name repetition.
```

Extend existing covergroup, note that therer is no name specified:
```sv
// All instances of covergroup g1 will be replaced by this stuff.
// This is usefull when we are deriving from some class with covergroup.
covergroup extends g1:        // Extending covergroup with name g1.
    ...                       // Same stuff as in regular covergroups.
endgroup : g1                 // End with optional name repetition.
```

Covergroup can take some parameters that are iether input or const ref:
```sv
covergroup g2 (ref int x, input int c);     // Input parameters x and c.
    coverpoint x;                           // Create coverponint for param.
    // Weight is used to compute total coverage of the group or coverpoints.
    option.weight = c;                      // Set weight to c.
    bit [7:0] d: coverpoint y[31:24];       // Cover only some bits.
endgroup : g2
```

Coverpoints can be also conditioned:
```sv
covergroup g3;
    coverpoint s0 iff (!reset);     // Sample only if reset is zero.
endgroup : g3
```

We can have less bins than values, the size of bins is equal to the
number of values divided by the number of bins (reminder go to the last bin):
```sv
covergroup g4;
    coverpoint regA
    {
        bins a    = { [0:63], 65 };
        bins b[]  = { [127:150], [148:191] };
        bins c[2] = { [1:3], 2, 6 };            // Bins: <1, 2>, <3, 2, 6>.
        bins d[2] = { 1 };                      // Bins: <1>, <>.
        bins e    = { [100:$] };                // Dolars is max value.

        bins others[] = default;                // Unmatched values separately.
    }
endgroup : g4
```

Things in coverpoint can be constrained using with statement and item:
```sv
covergroup g5;
    coverpoint regA
    {
        bins mod3[] = { [0:$] } with (item % 3 == 0);
        bins fmap[] = { [0:$] } with (func(item));
    }
endgroup : g5
```

Transitions between states:
```sv
covergroup g6;
    coverpoint regA
    {
        bins a     = (4 => 5 => 6), ([7:9], 10 => 11, 12);  // One of.
        bins arr[] = (4 => 5 => 6), ([7:9], 10 => 11, 12);  // All.

        // Transitions with unbound size (e.g., [-> 2]) cannot be used with
        // multiple bins construct - [].
        bins b = (12 => 3 [-> 2]);  // Sequence 12 => ... => 3 => ... => 3.

        bins c = (2 [-> 3:5]);            // 3 to 5 nonconsecutive 2's.
        bins d = (5 [* 3]);               // 3 consecutive 5's.
        bins e = (1 => 3 [-> 4:6] => 1);  // 1 => (... => 3)^[4:6] => 1.
        bins f = (1 => 3 [= 4:6] => 1);   // 1 => (... => 3)^[4:6] => ... => 1.

        bins other = default sequence;
    }
endgroup : g6
```

Bins can be ignored or removed, this apply to both values and sequences bins:
```sv
covergroup g7;
    coverpoint regA
    {
        ignore_bins ignored = { 1 };     // Excluded from coverage.
        ignore_bins seq_ign = (2 => 5);  // Ignore every sequence that was
                                         // matched but contains (2 => 5).

        illegal_bins bad = { 2 };   // Illegal bins produce runtime errors.

    }
endgroup : g7
```

Cross can have also bins:
```sv
covergroup g8;
    x: coverpoint regA
    {
        bins a = { 1 };
        bins b = { 2 };
    }

    y: coverpoint regB
    {
        bins a = { 1 };
        bins b = { 2 };
    }

    // Implicit bins for all combinations.
    x1: cross i, j;

    // One explicit bin for combinations where i = 0,
    // other are kept as in implicit (see x1).
    x2: cross i, j
    {
        bins i_zero = binsof(i) intersect { 0 };
        bins i_nonzero = ! binsof(i) intersect { 0 };

        // Exclusion will exclude ALL bins in coverpoint that even partially
        // touch any value within that range.
        bins something = ! binsof(i) intersect { [100:$] };
    }

    x3: cross x, y
    {
        bins foo = binsof(x.a) || binsof(y.b);
        bins bar = binsof(x.b) && binsof(x.b);
    }

    x4: cross x, y
    {
        // We can condition using with statement (similar as in coverpoints).
        // In addition, matches reqest minimal number of matched values, the
        // default value for matches is one, thus any value suffice.
        bins a = x4 with (x + y < 257) matches 127;

        // With can be either after single ow multiple bins of statements, and
        // can be even combined with the intersect keyword.
        bins b = ( binsof(x.a)     intersect { [0:50] }
                && binsof(b.a)     intersect { [0:50] } ) with (x == y);
        bins c = binsof(y.a) with (x > 12)
              || binsof(y.b) with (x & y & mask);
    }
endgroup : g8
```

Last but not least, there are some options:
```sv
covergroup g9;
    x: coverpoint regA
    {
        option.weight = 10;   // Weight of the coverpoint for total coverage.
        option.at_least = 3;  // Minimum number of hits for each bin to cover.
    }
endgroup : g9
```
