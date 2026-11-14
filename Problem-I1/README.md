# PMC (Przykładowa Maszyna Cyfrowa) - Task Solutions

This repository contains solutions to programming tasks for the **PMC (Przykładowa / Example Digital Machine)** architecture. 

## 📋 Task Overview: Task I1 - Square Root

* **Description:** For a given natural number $x \ge 0$ located in memory location number `100`, calculate the floor of the square root of $x$ (using addition) and save the result in memory location number `101`.
* **Example:**
  * **Input:** Memory cell `100` = `20` $\rightarrow$ **Output:** Memory cell `101` = `4` ($\lfloor\sqrt{20}\rfloor = 4$).

---

## ⚙️ File Format Specification

According to the platform requirements (e.g., Satori):
1. The first line of the submitted file must contain a natural number $n$ representing the total number of instructions in the file.
2. Each subsequent instruction must follow the format:
   ```text
   nr_komorki: rozkaz adresowanie liczba
   ```
3. C++ style comments (`//`) are allowed after spaces at the end of instruction lines.
4. Execution begins at memory cell number `0`.

---

## 🚀 Example Program Structure

```text
3
0: LOAD @ 30
1: STORE . 100   // example comment
2: STOP . 0
```
*(Note: Replace the example instructions above with the actual implementation of your square root algorithm).*

---

## 🛠️ Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/your-repo-name.git
   ```
2. Upload the relevant `.txt` solution file directly to the evaluation platform (e.g., Satori).