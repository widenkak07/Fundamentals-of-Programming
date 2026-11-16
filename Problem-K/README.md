# Task K: Land Division (Podział ziemi)

This repository contains a solution for **Task K: Land Division**, implemented in **C**. The problem originates from a competitive programming / algorithmic task set.

---

## 📌 Problem Description

Bajtazar works at the Bitock Land Office and is responsible for dividing agricultural areas for wealthy Bitock investors. Each square meter of land has a specific fertility level denoted by a non-negative integer. Farmers need areas where the fertility of each square meter is divisible by a certain number $k$. However, some farmers agree to let up to $b$ fields in their section *not* be divisible by $k$ to achieve a larger total area.

Bajtazar’s task is to take a strip of land of dimension $n \times 1$ meters and find the **best fragment**:
1. **Longest contiguous fragment** of land where at most $b$ fields have a fertility not divisible by $k$ (these non-divisible fields do not need to be adjacent).
2. If multiple fragments have the same maximum length, the one with the **highest average fertility** (arithmetic mean) is preferred.
3. If there are still ties in both length and average fertility, the one **furthest from the beginning** of the area is chosen.

---

## 📥 Input Format

* The first line contains an integer $z$ ($1 \le z \le 10^7$) — the number of test cases.
* For each test case:
  * The first line contains four integers: $n$, $k$, $b$, and $d$ ($1 \le n \le 10^6$, $1 \le k \le 10^3$, $0 \le b \le n$, $1 \le d \le 10$), representing:
    * $n$ — length of the land strip.
    * $k$ — the divisor for field fertility.
    * $b$ — maximum allowed number of non-divisible fields.
    * $d$ — decimal precision for outputting the average fertility.
  * The second line contains $n$ integers from the range $[0, 10^6]$, representing the fertility of consecutive fields.

---

## 📤 Output Format

For each test case:
* If no valid fragment exists (e.g., when $b = 0$ and no fields are divisible by $k$), output `NO`.
* If a valid fragment exists:
  * **Line 1:** Two values — the length of the best fragment (an integer) followed by the average fertility of that fragment formatted to $d$ decimal places.
  * **Line 2:** The fertility values of the consecutive fields belonging to the found fragment (in their original relative order).

---

## ⚠️ Constraints & Technical Details

* **Programming Language:** C
* **Available Memory:** 4–8 MB (depending on the test case)
* **Special Restriction:** Your keyboard is broken! You **cannot** use square brackets (`[` and `]`) anywhere in your source code (e.g., pointer arithmetic `*(arr + i)` must be used instead of array subscripting `arr[i]`).

---

## 💡 Example

### Input
```text
2
8 2 1 3
1 8 3 2 5 1 2 3
6 3 0 5
1 8 2 5 1 2
```

### Output
```text
3 4.333
8 3 2
NO
```

### Explanation
* **Test case 1:** We look for the longest subarray with at most $b = 1$ element not divisible by $k = 2$ (odd number). The longest valid subarrays have length $3$: `[1, 8, 3]` (avg $4.000$), `[8, 3, 2]` (avg $4.333$), `[2, 5, 1]` (not valid, 2 odds), `[5, 1, 2]` (not valid), `[1, 2, 3]` (not valid), etc. The fragment `8 3 2` has the highest average fertility ($13 / 3 \approx 4.333$). *(Note: Output formatting shows length and average on the first line, or separate lines depending on exact judge whitespace rules).*
* **Test case 2:** We need elements divisible by $k = 3$ with $b = 0$ exceptions. None of the numbers (`1 8 2 5 1 2`) are divisible by $3$, so the answer is `NO`.