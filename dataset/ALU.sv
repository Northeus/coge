module ALU(
    input logic CLK,
    input logic RST,
    input logic ACT,

    input logic[3:0]  OP,
    input logic[1:0]  MOVI,
    input logic[31:0] REG_A,
    input logic[31:0] REG_B,
    input logic[31:0] MEM,
    input logic[31:0] IMM,

    output logic[31:0] DATA,
    output logic       RDY,
    output logic       VLD,

    input logic COVERAGE_CAPTURE   // ignore coverage
);

    import "DPI-C" function void write_cov();       // ignore coverage
    always_ff @(posedge COVERAGE_CAPTURE) begin     // ignore coverage
        write_cov();                                // ignore coverage
    end                                             // ignore coverage

    typedef enum logic [1:0] {
        INIT,
        FIRST_STAGE,
        MUL_FIRST_STAGE,
        MUL_SECOND_STAGE
    } state_type;

    state_type state_curr;
    state_type state_next;

    always_comb begin
        case (state_curr)
            INIT:
                if (ACT) begin
                    if (mult_req)
                        state_next = MUL_FIRST_STAGE;
                    else
                        state_next = FIRST_STAGE;
                end else
                     state_next = INIT;
            FIRST_STAGE:      state_next = INIT;
            MUL_FIRST_STAGE:  state_next = MUL_SECOND_STAGE;
            MUL_SECOND_STAGE: state_next = INIT;
        endcase
    end

    always_ff @(posedge CLK) begin
        if (RST) begin
            state_curr  <= INIT;
        end else begin
            state_curr <= state_next;

            if (state_next == MUL_FIRST_STAGE)
                mult_res <= operand_A * operand_B;
        end
    end

    always_comb begin
        case (state_curr)
            INIT:             DATA = 32'b0;
            FIRST_STAGE:      DATA = norm_res;
            MUL_FIRST_STAGE:  DATA = mult_res[31:0];
            MUL_SECOND_STAGE: DATA = mult_res[63:32];
        endcase
    end

    logic[31:0] operand_A;
    logic[31:0] operand_B;

    logic[31:0] norm_res;
    logic[63:0] mult_res;
    logic       mult_req;

    assign operand_A = REG_A;

    assign VLD = (state_curr != INIT) & ~RST;
    assign RDY = state_curr == INIT;

    always_comb begin
        case (MOVI)
            2'b00:   operand_B = REG_B;
            2'b01:   operand_B = MEM;
            2'b10:   operand_B = IMM;
            default: operand_B = '0;
        endcase
    end

    always_comb begin
        norm_res = 32'b0;
        mult_req = 0;
        if (RDY) begin
            case (OP)
                4'b0000: norm_res = operand_A + operand_B;            // add
                4'b0001: norm_res = operand_A - operand_B;            // sub
                4'b0010: mult_req = 1;                                // mul
                4'b0011: norm_res = {1'b0, operand_B[31:1]};          // srl
                4'b0100: norm_res = {operand_B[30:0], 1'b0};          // sll
                4'b0101: norm_res = {operand_B[0], operand_B[31:1]};  // ror
                4'b0110: norm_res = {operand_B[30:0], operand_B[31]}; // rol
                4'b0111: norm_res = ~operand_B;                       // not
                4'b1000: norm_res = operand_A & operand_B;            // and
                4'b1001: norm_res = operand_A | operand_B;            // or
                4'b1010: norm_res = operand_A ^ operand_B;            // xor
                4'b1011: norm_res = ~(operand_A & operand_B);         // nand
                4'b1100: norm_res = ~(operand_A | operand_B);         // nor
                4'b1101: norm_res = ~(operand_A ^ operand_B);         // xnor
                4'b1110: norm_res = operand_B + 1;                    // inc
                4'b1111: norm_res = operand_B - 1;                    // dec
            endcase
        end
    end

endmodule
