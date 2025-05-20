covergroup foo;
    coverpoint foo;

    coverpoint x
    {
        bins a = 0;
        bins b = {0};
        bins c = {1, 2};
        bins d = {[5:6]};
    }

    some_arrays: coverpoint y
    {
        bins a[3] = {0 + 2, 1, 2};
        bins b[5] = {1, 2, 3};
        bins c[]  = {[4:6]};
        bins d[]  = {[4:$], 7};
    }

    some_special: coverpoint z
    {
        bins         a = {0};
        ignore_bins  b = {1};
        illegal_bins c = {2};
        bins         d = default;
    }
endgroup : foo
