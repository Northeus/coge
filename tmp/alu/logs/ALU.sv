//      // verilator_coverage annotation
        module ALU(
 001997     input logic CLK,
 000020     input logic RST,
 000519     input logic ACT,
        
 000546     input logic[3:0]  OP,
 000543     input logic[1:0]  MOVI,
 000528     input logic[31:0] REG_A,
 000538     input logic[31:0] REG_B,
 000532     input logic[31:0] MEM,
 000533     input logic[31:0] IMM,
        
 000028     output logic[31:0] DATA,
 000645     output logic       RDY,
 000644     output logic       VLD,
        
 000199     input logic COVERAGE_CAPTURE   // ignore coverage
        );
        
            import "DPI-C" function void write_cov();       // ignore coverage
 000099     always_ff @(posedge COVERAGE_CAPTURE) begin    // ignore coverage
 000099         write_cov();                                // ignore coverage
            end                                             // ignore coverage
        
            typedef enum logic [1:0] {
                INIT,
                FIRST_STAGE,
                MUL_FIRST_STAGE,
                MUL_SECOND_STAGE
            } state_type;
        
 000644     state_type state_curr;
 000827     state_type state_next;
        
 000528     logic[31:0] operand_A;
 000500     logic[31:0] operand_B;
        
 000646     logic[31:0] norm_res;
 000014     logic[63:0] mult_res;
 000108     logic       mult_req;
        
            assign operand_A = REG_A;
        
            assign VLD = (state_curr != INIT) & ~RST;
            assign RDY = state_curr == INIT;
        
 004996     always_comb begin
 004996         case (MOVI)
 001197             2'b00:   operand_B = REG_B;
 001218             2'b01:   operand_B = MEM;
 001265             2'b10:   operand_B = IMM;
 001316             default: operand_B = '0;
                endcase
            end
        
 005995     always_comb begin
 005995         norm_res = 32'b0;
 005995         mult_req = 0;
 003949         if (RDY) begin
 003949             case (OP)
 000267                 4'b0000: norm_res = operand_A + operand_B;            // add
 000261                 4'b0001: norm_res = operand_A - operand_B;            // sub
 000205                 4'b0010: mult_req = 1;                                // mul
 000248                 4'b0011: norm_res = {1'b0, operand_B[31:1]};          // srl
 000279                 4'b0100: norm_res = {operand_B[30:0], 1'b0};          // sll
 000245                 4'b0101: norm_res = {operand_B[0], operand_B[31:1]};  // ror
 000276                 4'b0110: norm_res = {operand_B[30:0], operand_B[31]}; // rol
 000198                 4'b0111: norm_res = ~operand_B;                       // not
 000212                 4'b1000: norm_res = operand_A & operand_B;            // and
 000238                 4'b1001: norm_res = operand_A | operand_B;            // or
 000226                 4'b1010: norm_res = operand_A ^ operand_B;            // xor
 000214                 4'b1011: norm_res = ~(operand_A & operand_B);         // nand
 000354                 4'b1100: norm_res = ~(operand_A | operand_B);         // nor
 000277                 4'b1101: norm_res = ~(operand_A ^ operand_B);         // xnor
 000271                 4'b1110: norm_res = operand_B + 1;                    // inc
 000178                 4'b1111: norm_res = operand_B - 1;                    // dec
                    endcase
                end
            end
        
 005995     always_comb begin
 005995         case (state_curr)
 003949             INIT:
 002134                 if (ACT) begin
 001704                     if (mult_req)
 000111                         state_next = MUL_FIRST_STAGE;
                            else
 001704                         state_next = FIRST_STAGE;
                        end else
 002134                      state_next = INIT;
 001818             FIRST_STAGE:      state_next = INIT;
 000114             MUL_FIRST_STAGE:  state_next = MUL_SECOND_STAGE;
 000114             MUL_SECOND_STAGE: state_next = INIT;
                endcase
            end
        
 000999     always_ff @(posedge CLK) begin
 000989         if (RST) begin
 000010             state_curr  <= INIT;
 000989         end else begin
 000989             state_curr <= state_next;
        
 000970             if (state_next == MUL_FIRST_STAGE)
 000019                 mult_res <= operand_A * operand_B;
                end
            end
        
 005995     always_comb begin
 005995         case (state_curr)
 003949             INIT:             DATA = 32'b0;
 001818             FIRST_STAGE:      DATA = norm_res;
 000114             MUL_FIRST_STAGE:  DATA = mult_res[31:0];
 000114             MUL_SECOND_STAGE: DATA = mult_res[63:32];
                endcase
            end
        
        endmodule
        
