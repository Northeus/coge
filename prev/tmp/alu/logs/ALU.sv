//      // verilator_coverage annotation
        module ALU(
 001997     input logic CLK,
 000030     input logic RST,
 000480     input logic ACT,
        
 000513     input logic[3:0]  OP,
 000514     input logic[1:0]  MOVI,
 000527     input logic[31:0] REG_A,
 000525     input logic[31:0] REG_B,
 000532     input logic[31:0] MEM,
 000528     input logic[31:0] IMM,
        
 000024     output logic[31:0] DATA,
 000661     output logic       RDY,
 000660     output logic       VLD,
        
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
        
 000660     state_type state_curr;
 000836     state_type state_next;
        
 000527     logic[31:0] operand_A;
 000497     logic[31:0] operand_B;
        
 000652     logic[31:0] norm_res;
 000012     logic[63:0] mult_res;
 000120     logic       mult_req;
        
            assign operand_A = REG_A;
        
            assign VLD = (state_curr != INIT) & ~RST;
            assign RDY = state_curr == INIT;
        
 004996     always_comb begin
 004996         case (MOVI)
 001186             2'b00:   operand_B = REG_B;
 001180             2'b01:   operand_B = MEM;
 001250             2'b10:   operand_B = IMM;
 001380             default: operand_B = '0;
                endcase
            end
        
 005995     always_comb begin
 005995         norm_res = 32'b0;
 005995         mult_req = 0;
 003925         if (RDY) begin
 003925             case (OP)
 000211                 4'b0000: norm_res = operand_A + operand_B;            // add
 000274                 4'b0001: norm_res = operand_A - operand_B;            // sub
 000235                 4'b0010: mult_req = 1;                                // mul
 000216                 4'b0011: norm_res = {1'b0, operand_B[31:1]};          // srl
 000252                 4'b0100: norm_res = {operand_B[30:0], 1'b0};          // sll
 000308                 4'b0101: norm_res = {operand_B[0], operand_B[31:1]};  // ror
 000264                 4'b0110: norm_res = {operand_B[30:0], operand_B[31]}; // rol
 000224                 4'b0111: norm_res = ~operand_B;                       // not
 000249                 4'b1000: norm_res = operand_A & operand_B;            // and
 000214                 4'b1001: norm_res = operand_A | operand_B;            // or
 000251                 4'b1010: norm_res = operand_A ^ operand_B;            // xor
 000227                 4'b1011: norm_res = ~(operand_A & operand_B);         // nand
 000267                 4'b1100: norm_res = ~(operand_A | operand_B);         // nor
 000271                 4'b1101: norm_res = ~(operand_A ^ operand_B);         // xnor
 000207                 4'b1110: norm_res = operand_B + 1;                    // inc
 000255                 4'b1111: norm_res = operand_B - 1;                    // dec
                    endcase
                end
            end
        
 005995     always_comb begin
 005995         case (state_curr)
 003925             INIT:
 002058                 if (ACT) begin
 001769                     if (mult_req)
 000098                         state_next = MUL_FIRST_STAGE;
                            else
 001769                         state_next = FIRST_STAGE;
                        end else
 002058                      state_next = INIT;
 001890             FIRST_STAGE:      state_next = INIT;
 000090             MUL_FIRST_STAGE:  state_next = MUL_SECOND_STAGE;
 000090             MUL_SECOND_STAGE: state_next = INIT;
                endcase
            end
        
 000999     always_ff @(posedge CLK) begin
 000984         if (RST) begin
 000015             state_curr  <= INIT;
 000984         end else begin
 000984             state_curr <= state_next;
        
 000969             if (state_next == MUL_FIRST_STAGE)
 000015                 mult_res <= operand_A * operand_B;
                end
            end
        
 005995     always_comb begin
 005995         case (state_curr)
 003925             INIT:             DATA = 32'b0;
 001890             FIRST_STAGE:      DATA = norm_res;
 000090             MUL_FIRST_STAGE:  DATA = mult_res[31:0];
 000090             MUL_SECOND_STAGE: DATA = mult_res[63:32];
                endcase
            end
        
        endmodule
        
