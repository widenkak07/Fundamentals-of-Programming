# Base Converter (Lazy Jack G1)

A C-based command-line utility designed to perform fast positional base conversions between arbitrary number systems.

## Overview

The program converts positive natural numbers represented as strings between arbitrary bases $p$ and $q$ (where $2 \le p, q \le 16$). Digits greater than 9 are represented using uppercase hex characters (`A`–`F`).

## Features

- **Arbitrary Base Conversion:** Supports conversions between base-2 and base-16.
- **Large Integer Handling:** Supports input string lengths up to 60 characters (decimal values up to $10^{18}$).
- **High Performance:** Optimized for processing up to $10^7$ test cases efficiently under strict memory constraints (4 MB).

## Input Format

1. The first line contains an integer $z$ ($1 \le z \le 10^7$) representing the number of test cases.
2. Each test case consists of a single command line:
   ```text
   CONVERT p q number
   ```
   - `p`: Source base ($2 \le p \le 16$)
   - `q`: Target base ($2 \le q \le 16$)
   - `number`: Source value as a string

## Output Format

For each `CONVERT` command, output the resulting number in the target base $q$ on a new line.

## Example

### Input
```text
8
CONVERT 10 2 7
CONVERT 2 10 1010
CONVERT 2 8 101011
CONVERT 3 9 12012
CONVERT 5 8 12340
CONVERT 2 16 101001
CONVERT 16 2 BC
```

### Output
```text
111
10
53
165
1712
29
10111100
```

## Build & Execution

Compile using any standard C compiler (e.g., `gcc`):

```bash
gcc -O3 main.c -o base_converter
./base_converter < input.txt
```