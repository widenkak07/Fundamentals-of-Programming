# Two's Complement Register Simulator (Lazy Jack G2)

A low-level C program that simulates register storage and manipulation using Two's Complement binary representation.

## Overview

This tool emulates $r$-bit hardware registers (with sizes ranging from $r = 4$ to $r = 64$ bits). It converts signed decimal integers into two's complement binary strings and decodes binary register states back into decimal values.

## Features

- **Bit-Width Validation:** Supports register sizes $r \in [4, 64]$. Overflow detection returns `ERROR` if a value cannot fit in the designated register width.
- **Signed Arithmetic Encoding:** Handles positive and negative numbers seamlessly using Two's Complement format.
- **Decoding Utility:** Parses raw binary strings and outputs their signed decimal representation.
- **Low Memory Overhead:** Runs within a strict 4 MB memory budget.

## Commands

- `WRITE r x`: Encodes decimal signed integer $x$ into an $r$-bit two's complement binary string. Outputs `ERROR` if $x$ overflows the $r$-bit signed integer range $[-2^{r-1}, 2^{r-1}-1]$.
- `READ register`: Accepts a binary string `register` (formatted in two's complement) and outputs its decimal signed integer equivalent.

## Input Format

1. The first line contains an integer $z$ ($1 \le z \le 10^7$) — the number of command sets.
2. Subsequent lines contain individual `WRITE` or `READ` commands.

## Output Format

Outputs the binary register string, converted decimal integer, or `ERROR` for each command.

## Example

### Input
```text
7
WRITE 8 12
WRITE 8 -12
WRITE 8 -128
WRITE 8 -130
READ 00001100
READ 01111111
READ 11111111
```

### Output
```text
00001100
11110100
10000000
ERROR
12
127
-1
```

## Build & Execution

Compile using any standard C compiler (e.g., `gcc`):

```bash
gcc -O3 main.c -o register_sim
./register_sim < input.txt
```