//      // verilator_coverage annotation
        module arithmetic_unit (
 054693     input logic CLK,  // Clock signal.
%000002     input logic RST,  // Reset signal (asynchronnous, positive active).
 020000     input logic ACT,  // Activation signal (1 - start computation).
        
 004928     input logic [1:0]  OP_CODE,  // Operator selector (+, -, *, /).
 004942     input logic [1:0]  MOVI,     // Second operand selector (REG_B, MEM, IMM, ?).
 004887     input logic [31:0] REG_A,    // First operand.
 004912     input logic [31:0] REG_B,    // Second operand iff MOVI is 0.
 004889     input logic [31:0] MEM,      // Second operand iff MOVI is 1.
 004924     input logic [31:0] IMM,      // Second operand iff MOVI is 2.
        
 004408     output logic [31:0] DATA,       // Result of the operation iff DATA_VALID is 1.
 020000     output logic        DATA_VALID  // Data valid flag, result is stored in DATA.
        );
        
            typedef enum logic [1:0] {
                ADD = 2'b00,
                SUB = 2'b01,
                MUL = 2'b10,
                DIV = 2'b11
            } opcode_t;
        
 004887     logic [31:0] operand_a;
 004584     logic [31:0] operand_b;
        
            assign operand_a = REG_A;
        
 136731     always_comb begin
 136731         case (MOVI)
 035461             2'b00: operand_b = REG_B;
 033505             2'b01: operand_b = MEM;
 033490             2'b10: operand_b = IMM;
 034275             2'b11: operand_b = 0;
                endcase
            end
        
 004894     logic [1:0]  mul_counter;
 004894     logic        mul_busy;
        
 027347     always_ff @(posedge CLK or posedge RST) begin
%000002         if (RST) begin
%000002             DATA <= 0;
%000002             DATA_VALID <= 0;
%000002             mul_counter <= 0;
%000002             mul_busy <= 0;
 027345         end else begin
 010000             if (ACT && !mul_busy) begin
 002447                 if (OP_CODE == MUL) begin
 002447                     DATA_VALID <= 0;
 002447                     mul_counter <= 0;
 002447                     mul_busy <= 1;
 007553                 end else begin
 007553                     DATA_VALID <= 1;
                            /* verilator lint_off CASEINCOMPLETE */
 007553                     unique case (OP_CODE)
 002500                         ADD: DATA <= operand_a + operand_b;
 002469                         SUB: DATA <= operand_a - operand_b;
 002584                         DIV: DATA <= operand_b != 0 ? operand_a / operand_b : 32'b0;
                            endcase
                            /* verilator lint_on CASEINCOMPLETE */
                        end
 007341             end else if (mul_busy) begin
 002447                 if (mul_counter == 2) begin
 002447                     DATA_VALID <= 1;
 002447                     DATA <= operand_a * operand_b;
 002447                     mul_counter <= 0;
 002447                     mul_busy <= 0;
 004894                 end else begin
 004894                     mul_counter <= mul_counter + 1;
                        end
 010004             end else begin
 010004                 DATA_VALID <= 0;
                    end
                end
            end
        
        endmodule
        
