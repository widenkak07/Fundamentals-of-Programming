# Task B1: Sieve of Eratosthenes

An algorithmic solution for efficiently counting prime numbers within given ranges and finding the smallest prime divisors.

## Problem Description

The task requires processing a large number of queries ($1 \le z \le 10^7$) concerning ranges $[a, b]$ (where $1 \le a \le b \le 10^7$). For each query, the program must output:

1. The number of prime numbers located in the range $[a, b]$ (inclusive).
2. The smallest prime factor of number $a$ (or the number $a$ itself if it is prime or equals $1$).
3. The smallest prime factor of number $b$ (or the number $b$ itself if it is prime or equals $1$).

### Technical Constraints:

* **Available memory:** $128\text{ MB}$
* **Programming language:** C
* **Maximum value of numbers:** $10^7$

## Algorithmic Approach

Due to strict time limits with up to $10^7$ queries, the solution implements two key techniques:

* **SPF Array (Smallest Prime Factor):** A modified Sieve of Eratosthenes that records the smallest prime divisor for each number.
* **Prefix Sums:** An auxiliary array tracking the cumulative count of prime numbers, allowing each range query to be answered in constant time $\mathcal{O}(1)$.
* **Memory Complexity:** Two arrays of size $10^7$ of type `int` consume roughly $80\text{ MB}$, safely fitting within the $128\text{ MB}$ limit.

## Compilation and Running

To compile and run the program on Linux with maximum compiler optimization, use the following commands:

```bash
gcc -O3 rozwiazanie.c -o rozwiazanie
./rozwiazanie
```

## Example

### Input:

```
8
1 10
1 100
505 999
2 19
25 28
3 35
71 121
221 323
```

### Output:

```
4 1 2
25 1 2
72 5 3
8 2 19
0 5 2
10 3 5
11 71 11
19 13 17
```