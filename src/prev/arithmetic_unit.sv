module arithmetic_unit (
    input logic CLK,  // Clock signal.
    input logic RST,  // Reset signal (asynchronnous, positive active).
    input logic ACT,  // Activation signal (1 - start computation).

    input logic COV,

    input logic [1:0]  OP_CODE,  // Operator selector (+, -, *, /).
    input logic [1:0]  MOVI,     // Second operand selector (REG_B, MEM, IMM, ?).
    input logic [31:0] REG_A,    // First operand.
    input logic [31:0] REG_B,    // Second operand iff MOVI is 0.
    input logic [31:0] MEM,      // Second operand iff MOVI is 1.
    input logic [31:0] IMM,      // Second operand iff MOVI is 2.

    output logic [31:0] DATA,       // Result of the operation iff DATA_VALID is 1.
    output logic        DATA_VALID  // Data valid flag, result is stored in DATA.
);

    import "DPI-C" function void write_cov(input string fname);
    always_ff @(posedge COV) begin
        write_cov("partial_cov.dat");
    end

    typedef enum logic [1:0] {
        ADD = 2'b00,
        SUB = 2'b01,
        MUL = 2'b10,
        DIV = 2'b11
    } opcode_t;

    logic [31:0] operand_a;
    logic [31:0] operand_b;

    assign operand_a = REG_A;

    always_comb begin
        case (MOVI)
            2'b00: operand_b = REG_B;
            2'b01: operand_b = MEM;
            2'b10: operand_b = IMM;
            2'b11: operand_b = 0;
        endcase
    end

    logic [1:0]  mul_counter;
    logic        mul_busy;

    always_ff @(posedge CLK or posedge RST) begin
        if (RST) begin
            DATA <= 0;
            DATA_VALID <= 0;
            mul_counter <= 0;
            mul_busy <= 0;
        end else begin
            if (ACT && !mul_busy) begin
                if (OP_CODE == MUL) begin
                    DATA_VALID <= 0;
                    mul_counter <= 0;
                    mul_busy <= 1;
                end else begin
                    DATA_VALID <= 1;
                    /* verilator lint_off CASEINCOMPLETE */
                    unique case (OP_CODE)
                        ADD: DATA <= operand_a + operand_b;
                        SUB: DATA <= operand_a - operand_b;
                        DIV: DATA <= operand_b != 0 ? operand_a / operand_b : 32'b0;
                    endcase
                    /* verilator lint_on CASEINCOMPLETE */
                end
            end else if (mul_busy) begin
                if (mul_counter == 2) begin
                    DATA_VALID <= 1;
                    DATA <= operand_a * operand_b;
                    mul_counter <= 0;
                    mul_busy <= 0;
                end else begin
                    mul_counter <= mul_counter + 1;
                end
            end else begin
                DATA_VALID <= 0;
            end
        end
    end

endmodule
