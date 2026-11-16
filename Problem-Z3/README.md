# Z3. The Check (Czek)

A C/C++ solution to **The Check** algorithmic problem.

## 📋 Problem Description

One sunny day, Johnny went for a walk along the Vistula River boulevard, enjoying the lovely weather and his favorite carrot juice. While throwing away the empty bottle, he noticed some torn pieces of paper lying next to the trash can. Upon picking them up, he discovered they were fragments of a torn check, with each piece containing a single digit.

In Bajtland, where Johnny lives, numbers and checks follow specific rules:
* Numbers are written in base $P$ (rather than the decimal system).
* For a check to be valid, the amount must be divisible by $P - 1$.

**Task:** Help Johnny assemble the check to obtain the **maximum possible sum**.

Since the sought number can be very large, you only need to output specific digits upon request. Note that the representation of a positive number cannot have leading zeros, and the only valid representation of zero is `0`. For positional systems with a base greater than 10, digits are separated by spaces to avoid ambiguity.

## ⚙️ Constraints & Requirements

* **Language:** C or C++
* **Memory Limit:** 16 MB
* **Number of data sets ($z$):** $1 \le z \le 10^7$
* **Base ($P$):** $2 \le P \le 10^6$
* **Number of queries ($q$):** $1 \le q \le 10^5$
* **Digit counts ($a_i$):** $1 \le a_i \le 10^6$
* **Query index ($k_i$):** $0 \le k_i \le 10^{18}$

## 📥 Input

The first line of standard input contains an integer $z$ ($1 \le z \le 10^7$) — the number of data sets, which appear sequentially.

For each data set:
1. The first line contains two integers $P$ and $q$ ($2 \le P \le 10^6$, $1 \le q \le 10^5$) separated by a space, representing the base of the number system and the number of queries.
2. The second line contains a sequence of $P$ integers $a_0, a_1, \dots, a_{P-1}$ ($1 \le a_i \le 10^6$) separated by spaces, where $a_i$ denotes the number of paper pieces with the digit $i$.
3. The next $q$ lines contain queries: the $i$-th of these lines contains a single integer $k_i$ ($0 \le k_i \le 10^{18}$).

## 📤 Output

For each data set, output $q$ lines:
* The $i$-th line should contain the $k_i$-th digit of the largest number in base $P$ divisible by $P - 1$ that Johnny can form using his available pieces.
* Digits are numbered from the right side (starting from the least significant digit at index `0`).
* If the sought number has at most $k_i$ digits, output `-1` on that line.

## 💡 Example

### Input

```text
1
3 4
1 1 1
0
1
2
3
```

### Output

```text
0
2
-1
-1
```

## 🛠️ Compilation & Usage

To compile and run the solution using `g++` (or `gcc` for C):

```bash
g++ -O3 -Wall -Wextra main.cpp -o check
./check < input.txt
```