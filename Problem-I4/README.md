# Task I4\*: Counter

Solution for **Task I4\*** designed for the **PMC (Przykładowa Maszyna Cyfrowa)** architecture.

## 📋 Problem Description

Cell number `50` contains the natural number $1 \le n \le 460$, and cell number `51` contains the natural number $d = 2^k$, where $k \in \{0, \dots, 7\}$. The following $n$ cells (`52` to `51 + n`) contain natural numbers.

1. Count how many of these numbers are divisible by $d$ and write the determined count to cell `48`.
2. Write the memory address of the **last** number divisible by $d$ to cell `49`. If there are no numbers divisible by $d$, write `-1` in cell `49`.

### Example

* **Input:**
  * `50`: `5` *(count* $n$ *of numbers)*
  * `51`: `8` *(divisor* $d = 2^3$*)*
  * **Numbers (`52`–`56`):** `52: 12`, `53: 16`, `54: 9`, `55: 24`, `56: 2`
* **Output:**
  * `48`: `2` *(two numbers divisible by 8: `16` and `24`)*
  * `49`: `55` *(address of `24`, the last number divisible by 8)*

## ⚙️ File Format Specification (PMC / Satori)

1. The first line of the submitted file must contain a natural number $n$ representing the total number of instructions in the file.
2. Each subsequent instruction must follow the format:
   ```text
   nr_komorki: rozkaz adresowanie liczba
   ```
3. C++ style comments (`//`) are allowed after spaces at the end of instruction lines.
4. Execution begins at memory cell number `0`.