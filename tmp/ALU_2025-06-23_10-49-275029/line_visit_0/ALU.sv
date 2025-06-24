//      // verilator_coverage annotation
        module ALU(
 001001     input logic CLK,
 000002     input logic RST,
 000240     input logic ACT,
        
 000240     input logic[3:0]  OP,
 000244     input logic[1:0]  MOVI,
 000231     input logic[31:0] REG_A,
 000232     input logic[31:0] REG_B,
 000228     input logic[31:0] MEM,
 000237     input logic[31:0] IMM,
        
%000000     output logic[31:0] DATA,
 000321     output logic       RDY,
 000320     output logic       VLD
        );
        
            typedef enum logic [1:0] {
                INIT,
                FIRST_STAGE,
                MUL_FIRST_STAGE,
                MUL_SECOND_STAGE
            } state_type;
        
 000016     state_type state_curr;
 000028     state_type state_next;
        
 000231     logic[31:0] operand_A;
 000204     logic[31:0] operand_B;
        
 000288     logic[31:0] norm_res;
 000006     logic[63:0] mult_res;
 000056     logic       mult_req;
        
            assign operand_A = REG_A;
            assign mult_req  = OP == 4'b0010;
        
            assign VLD = (state_curr != INIT) & ~RST;
            assign RDY = state_curr == INIT;
        
 002506     always_comb begin
 002506         case (MOVI)
 000667             2'b00:   operand_B = REG_B;
 000656             2'b01:   operand_B = MEM;
 000580             2'b10:   operand_B = IMM;
 000603             default: operand_B = '0;
                endcase
            end
        
 003007     always_comb begin
 003007         norm_res = 32'b0;
 003007         mult_res = 64'b0;
 001008         if (RDY) begin
 001999             case (OP)
 000170                 4'b0000: norm_res = operand_A + operand_B;            // add
 000127                 4'b0001: norm_res = operand_A - operand_B;            // sub
 000118                 4'b0010: mult_res = operand_A * operand_B;            // mul
 000121                 4'b0011: norm_res = {1'b0, operand_B[31:1]};          // srl
 000126                 4'b0100: norm_res = {operand_B[30:0], 1'b0};          // sll
 000116                 4'b0101: norm_res = {operand_B[0], operand_B[31:1]};  // ror
 000109                 4'b0110: norm_res = {operand_B[30:0], operand_B[31]}; // rol
 000156                 4'b0111: norm_res = ~operand_B;                       // not
 000137                 4'b1000: norm_res = operand_A & operand_B;            // and
 000101                 4'b1001: norm_res = operand_A | operand_B;            // or
 000119                 4'b1010: norm_res = operand_A ^ operand_B;            // xor
 000124                 4'b1011: norm_res = ~(operand_A & operand_B);         // nand
 000158                 4'b1100: norm_res = ~(operand_A | operand_B);         // nor
 000119                 4'b1101: norm_res = ~(operand_A ^ operand_B);         // xnor
 000090                 4'b1110: norm_res = operand_B + 1;                    // inc
 000108                 4'b1111: norm_res = operand_B - 1;                    // dec
%000000                 default: norm_res = '0;
                    endcase
                end
            end
        
%000000     always_comb begin
%000000         case (state_curr)
%000000             INIT: case ({ACT, mult_req})
%000000                     2'b10:   state_next = FIRST_STAGE;
%000000                     2'b11:   state_next = MUL_FIRST_STAGE;
%000000                     default: state_next = INIT;
                    endcase
%000000             FIRST_STAGE:      state_next = INIT;
%000000             MUL_FIRST_STAGE:  state_next = MUL_SECOND_STAGE;
%000000             MUL_SECOND_STAGE: state_next = INIT;
                endcase
            end
        
 000501     always_ff @(posedge CLK) begin
 000001         if (RST) begin
 000001             state_curr  <= INIT;
                end else
 000500             state_curr <= state_next;
            end
        
 003007     always_comb begin
 003007         case (state_curr)
 001999             INIT:             DATA = 32'b0;
 000912             FIRST_STAGE:      DATA = norm_res;
 000048             MUL_FIRST_STAGE:  DATA = mult_res[31:0];
 000048             MUL_SECOND_STAGE: DATA = mult_res[63:32];
                endcase
            end
        
        endmodule
        
