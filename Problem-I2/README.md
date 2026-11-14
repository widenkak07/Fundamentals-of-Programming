# Task I2: Missing Number

Solution for **Task I2 (Missing Number)** designed for the **PMC (Przykładowa Maszyna Cyfrowa)** architecture.

## 📋 Problem Description

Cell number `50` contains a natural number $1 \le n \le 461$. The following $n$ memory cells (`51` to `50 + n`) contain natural numbers. Determine the number that occurs **exactly once**, knowing that all remaining numbers occur **exactly twice**. Record the determined value in memory cell `49`.

* **Hint:** Use the `XOR` bitwise operation.

### Example
* **Input:**
  * `50`: `7` *(count of numbers)*
  * `51`: `17`, `52`: `3`, `53`: `17`, `54`: `5`, `55`: `4`, `56`: `3`, `57`: `5`
* **Output:**
  * `49`: `4`

## ⚙️ File Format Specification (PMC / Satori)

1. The first line of the submitted file must contain a natural number $n$ representing the total number of instructions in the file.
2. Each subsequent instruction must follow the format:
   ```text
   nr_komorki: rozkaz adresowanie liczba
   ```
3. C++ style comments (`//`) are allowed after spaces at the end of instruction lines.
4. Execution begins at memory cell number `0`.