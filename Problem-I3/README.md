# Task I3*: Intersection of Ordered Sequences

Solution for **Task I3\*** designed for the **PMC (Przykładowa Maszyna Cyfrowa)** architecture.

## 📋 Problem Description

Cell number `50` contains the natural number $n$ ($1 \le n \le 100$). The following cells, from `51` to `50 + n`, contain elements of the non-decreasing sequence $A$. Cells from `51 + n` to `50 + 2n` contain elements of the non-decreasing sequence $B$. Determine the size of the intersection of the sequences $A$ and $B$ and record the result in cell `49`.

### Example
* **Input:**
  * `50`: `5` *(length $n$ of each sequence)*
  * **Sequence $A$ (`51`–`55`):** `2`, `5`, `10`, `12`, `12`
  * **Sequence $B$ (`56`–`60`):** `2`, `11`, `12`, `12`, `12`
* **Output:**
  * `49`: `3` *(matching elements: `2`, `12`, `12`)*

## ⚙️ File Format Specification (PMC / Satori)

1. The first line of the submitted file must contain a natural number $n$ representing the total number of instructions in the file.
2. Each subsequent instruction must follow the format:
   ```text
   nr_komorki: rozkaz adresowanie liczba
   ```
3. C++ style comments (`//`) are allowed after spaces at the end of instruction lines.
4. Execution begins at memory cell number `0`.