# High-Performance Matrix Operations Engine (Task H)

An optimized C library and command-line engine built to perform fast matrix multiplication and exponentiation under tight computational and memory constraints.

## Overview

Designed for large-scale calculations, this application executes dynamic matrix multiplication and calculates matrix powers up to $p = 10^6$. To deliver maximum execution speed while adhering to memory limits, it incorporates binary matrix exponentiation and cache-efficient traversal algorithms.

## Key Features

- **Matrix Multiplication (`MULTIPLY`):** Calculates matrix products $A \times B$ for dynamic sizes up to $1500 \times 1500$.
- **Binary Exponentiation (`POWER`):** Implements fast exponentiation algorithms with $O(N^3 \log p)$ time complexity to compute $A^p$ efficiently for $p \le 10^6$.
- **Cache Optimization:** Tailored loop ordering minimizes CPU cache misses during matrix traversal.
- **Modulo Output:** Output numbers are truncated to their last 3 digits (modulo 1000) to keep I/O operations lightweight.
- **Error Handling:** Gracefully outputs `ERROR MULTIPLY` when matrix dimensions are incompatible for multiplication ($m_1 \ne n_2$).

## Input Format

1. The first line specifies the total number of operation sets $z$ ($1 \le z \le 10^7$).
2. For each test set:
   - Operation line: `MULTIPLY` or `POWER p` ($1 \le p \le 10^6$).
   - Dimensions of Matrix 1: $n_1 \quad m_1$ ($1 \le n_1, m_1 \le 1500$), followed by $n_1$ lines containing $m_1$ non-negative integers ($\le 1000$).
   - (For `MULTIPLY` only): Dimensions of Matrix 2: $n_2 \quad m_2$ ($1 \le n_2, m_2 \le 1500$), followed by its corresponding elements.

## Output Format

Prints the resulting matrix elements formatted as their last 3 digits. If an invalid multiplication dimension is encountered, outputs `ERROR MULTIPLY`.

## Technical Specifications

- **Language:** C
- **Memory Limit:** 20 MB
- **Complexity Target:** $O(N^3 \log p)$ for exponentiation with cache-aware memory layout.

## Build & Execution

Compile using any standard C compiler (e.g., `gcc` with high optimization flags):

```bash
gcc -O3 matrix_engine.c -o matrix_engine
./matrix_engine < input.txt
```