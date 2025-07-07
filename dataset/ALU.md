# ALU
The ALU module performs 32-bit arithmetic and logic operations on two input operands.
It supports a wide range of operations controlled by a 4-bit opcode and provides the
result along with status signals indicating operation validity and readiness.

## Inputs
| Name               | Width | Description                                      |
|--------------------|-------|--------------------------------------------------|
| `CLK`              | 1     | Clock signal (rising edge triggered)             |
| `RST`              | 1     | Synchronous reset, active high                   |
| `ACT`              | 1     | Operation activate signal                        |
| `OP`               | 4     | Operation code selecting the ALU operation       |
| `MOVI`             | 2     | Operand B selector: selects source for operand B |
| `REG_A`            | 32    | First 32-bit operand (fixed)                     |
| `REG_B`            | 32    | Second operand source option 1                   |
| `MEM`              | 32    | Second operand source option 2                   |
| `IMM`              | 32    | Second operand source option 3 (immediate value) |

## Outputs
| Name  | Width | Description                                         |
|-------|-------|---------------------------------------------------|
| `DATA`| 32    | ALU operation result                               |
| `RDY` | 1     | Ready flag: high when ALU can accept a new input  |
| `VLD` | 1     | Valid flag: high when output data is valid        |

## Operand B Selection (`MOVI`)
| `MOVI` | Operand B Source  |
|--------|-------------------|
| `00`   | `REG_B`           |
| `01`   | `MEM`             |
| `10`   | `IMM`             |
| others | Unsupported value |

## Supported Operations (`OP`)
| OP Code | Operation Description                         |
|---------|-----------------------------------------------|
| `0000`  | Addition: `REG_A + operand_B`                 |
| `0001`  | Subtraction: `REG_A - operand_B`              |
| `0010`  | Multiplication                                |
| `0011`  | Logical Shift Right (`operand_B` >> 1)        |
| `0100`  | Logical Shift Left (`operand_B` << 1)         |
| `0101`  | Rotate Right (`operand_B` rotated right by 1) |
| `0110`  | Rotate Left (`operand_B` rotated left by 1)   |
| `0111`  | Bitwise NOT of `operand_B`                    |
| `1000`  | Bitwise AND of `REG_A` and `operand_B`        |
| `1001`  | Bitwise OR of `REG_A` and `operand_B`         |
| `1010`  | Bitwise XOR of `REG_A` and `operand_B`        |
| `1011`  | Bitwise NAND of `REG_A` and `operand_B`       |
| `1100`  | Bitwise NOR of `REG_A` and `operand_B`        |
| `1101`  | Bitwise XNOR of `REG_A` and `operand_B`       |
| `1110`  | Increment (`operand_B + 1`)                   |
| `1111`  | Decrement (`operand_B - 1`)                   |

## Operation Flow
- On asserting `ACT`, the ALU begins the operation selected by `OP` using `REG_A` and the selected `operand_B`.
- For multiplication (`OP = 0010`), the 64-bit result is split and provided in two consecutive clock cycles: first the lower 32 bits, then the upper 32 bits.
- For all other operations, the result is available in the next cycle.
- `RDY` indicates when the ALU is ready to accept new inputs (high when idle).
- `VLD` signals when the output `DATA` contains valid result data.

## Additional Notes
- The module operates synchronously with respect to the rising edge of `CLK`.
- Reset (`RST`) synchronously resets the internal state and output signals.
