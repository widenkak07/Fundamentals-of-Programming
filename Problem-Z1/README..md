# Z1. Magic Sequence (Magiczny ciąg)

A C solution to the **Magic Sequence** (ECG sequence) algorithmic problem.

## 📋 Problem Description

Given is a sequence of positive integers $a_n$, called the **magic sequence**, defined as follows:
* $a_1 = 1$
* $a_2 = 2$
* For $n \ge 3$, $a_n$ is the smallest positive integer that has not yet appeared in the sequence and satisfies $\gcd(a_{n-1}, a_n) > 1$.

The first few terms of the sequence are:
$$1, 2, 4, 6, 3, 9, 12, 8, 10, 5, 15, 18, 14, 7, \dots$$

### Properties
* Every positive integer eventually appears in the sequence.
* Prime numbers appear in the sequence in strictly increasing order.

**Task:** Determine the 1-based position (index) of a given integer $a$ in the magic sequence.

---

## ⚙️ Constraints & Requirements

* **Language:** C
* **Memory Limit:** 128 MB
* **Number of queries ($z$):** $1 \le z \le 10^7$
* **Query value ($a$):** $1 \le a \le 3 \cdot 10^5$

---

## 📥 Input

The first line of standard input contains a single integer $z$ ($1 \le z \le 10^7$) — the number of queries.  
Each of the following $z$ lines contains a single integer $a$ ($1 \le a \le 3 \cdot 10^5$).

## 📤 Output

For each integer $a$ given in the input, output a single line containing its position in the magic sequence.

---

## 💡 Example

### Input
```text
7
5
11
15
127
332
299993
300000
```

### Output
```text
10
20
11
236
312
584898
292101
```

---

## 🛠️ Compilation & Usage

To compile and run the solution using `gcc`:

```bash
gcc -O3 -Wall -Wextra main.c -o magic_sequence
./magic_sequence < input.txt
```