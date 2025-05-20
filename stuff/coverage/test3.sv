covergroup test2;
    coverpoint foo;
    coverpoint bar
    {
        bins a[] = 0;
        bins b[] = {[1:3]};
        bins c[] = {4, [5:6], 7};
    }
endgroup
