# PMC Simulator (von Neumann Digital Machine)

A simulator of a simple von Neumann architecture digital machine (PMC - *Przykładowa Maszyna Cyfrowa*), written in C. The program parses symbolic assembly-like instructions, executes them on a simulated memory space, supports multiple test cases, and ignores single-line `//` comments.

## Features

- Simulates a 512-cell memory space (16-bit / 2-byte words) and core CPU registers (`AC` - Accumulator, `PC` - Program Counter, `IR` - Instruction Register).
- Supports all 15 standard PMC instructions and 4 addressing modes.
- Handles sign-magnitude representation for 10-bit instruction addresses and two's complement arithmetic in registers.
- Parses and ignores inline `//` comments (up to 200 characters).
- Processes multiple consecutive test cases within a single execution.

## Architecture & Data Representation

- **Memory:** 512 cells (`0` to `511`), each storing a 2-byte (16-bit) integer. Uninitialized cells default to `0`.
- **Registers:** Values in registers are stored using standard **two's complement** (*kod uzupełnieniowy*) representation.
- **Instruction Format:** 16-bit word divided into:
  - **4 bits:** Opcode (Instruction)
  - **2 bits:** Addressing mode
  - **10 bits:** Address/Operand field encoded in **sign-magnitude** (*znak-moduł*) representation (1st bit for sign, remaining 9 bits for absolute value).

## Instruction Set

| Opcode | Mnemonic | Description | Operation |
| :--- | :--- | :--- | :--- |
| `0000` | `NULL` | No operation | *Do nothing* |
| `0001` | `STOP` | Halt execution | Terminate program |
| `0010` | `LOAD` | Load operand into Accumulator | `AC <- OP` |
| `0011` | `STORE` | Store Accumulator value in memory | `M[OP] <- AC` |
| `0100` | `JUMP` | Unconditional jump | `PC <- OP` |
| `0101` | `JNEG` | Jump if Accumulator is negative | `if (AC < 0) PC <- OP` |
| `0110` | `JZERO` | Jump if Accumulator is zero | `if (AC == 0) PC <- OP` |
| `1000` | `ADD` | Add operand to Accumulator | `AC <- AC + OP` |
| `1001` | `SUB` | Subtract operand from Accumulator | `AC <- AC - OP` |
| `1100` | `AND` | Bitwise AND | `AC <- AC & OP` |
| `1101` | `OR` | Bitwise OR | `AC <- AC \| OP` |
| `1110` | `NOT` | Bitwise NOT (negation of AC) | `AC <- ~AC` |
| `1111` | `XOR` | Bitwise XOR | `AC <- AC ^ OP` |
| `1010` | `SHL` | Logical shift left | `AC <- AC << OP` |
| `1011` | `SHR` | Logical shift right | `AC <- AC >> OP` |

*(Note: For `STORE`, `JUMP`, `JNEG`, and `JZERO`, the effective address `OP` refers to the target memory location rather than the value stored inside it).*

## Addressing Modes

| Code | Symbol | Name | Operand Resolution (`OP`) |
| :--- | :---: | :--- | :--- |
| `00` | `.` | Immediate (*natychmiastowy*) | `OP := IR.adr` |
| `01` | `@` | Direct (*bezpośredni*) | `OP := M[IR.adr]` |
| `10` | `*` | Indirect (*pośredni*) | `OP := M[M[IR.adr]]` |
| `11` | `+` | Indexed (*indeksowy*) | `OP := M[AC + IR.adr]` |

## Input & Output Format

### Input
1. The first line contains an integer $z$ ($1 \le z \le 10^6$) — the number of test cases.
2. Each test case begins with two integers $n$ and $k$ ($1 \le n, k \le 512$), representing the number of initialized memory cells and the number of output cells to print.
3. The next $n$ lines describe the memory state in the format:
   `<address>: <value_or_instruction> [// optional comment]`
   - `<address>` is an integer $p$ ($0 \le p \le 511$).
   - `<value_or_instruction>` is either a 2-byte signed integer $x$ or a symbolic instruction: `<MNEMONIC> <MODE> <10-BIT_INT>`.
4. The final line of a test case contains $k$ space-separated integers specifying the memory addresses whose values should be printed after the program halts.

### Output
For each test case, print a single line containing the $k$ integer values stored in the requested memory cells. (If a printed cell contains an instruction, its address field is guaranteed to be non-negative).

## Building & Running

### Compilation
Compile the C source code using `gcc` (strictly adhering to the 4 MB memory limit):

```bash
gcc -O2 -Wall -Wextra main.c -o pmc_simulator
```

### Execution
Run the simulator by redirecting an input file to standard input:

```bash
./pmc_simulator < input.txt
```

## Example

### Input (`input.txt`)
```text
1
9 2
0: LOAD @ 20
1: SUB @ 21
2: STORE . 22
3: ADD @ 21
4: ADD @ 21
5: STORE . 23   // saving result
6: STOP . 0
20: 100
21: 50
22 23
```

### Output
```text
50 150
```