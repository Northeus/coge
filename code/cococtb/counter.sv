module counter(
    input  logic unsigned       clk,
    input  logic unsigned       rst,
    output logic unsigned [7:0] cnt
);

    always_ff @(posedge clk)
        if (rst)
            cnt <= 0;
        else
            cnt <= cnt + 1;

endmodule
