# Task E1: Numbers (3-SUM with Bubble Sort)

Given an array of $n$ integers, write an algorithm that determines whether there exist three numbers $a$, $b$, and $c$ in the array such that $a + b + c = 0$ (the numbers do not have to be distinct).

## Algorithm Requirements

For **Task E1**, you must use the **Bubble Sort** algorithm to sort the array.

## Input

* The first line of input contains an integer $z$ ($1 \le z \le 10^7$) — the number of test cases following in order.
* Description of a single test case:
  * The first line contains a natural number $n$ ($1 \le n \le 10^5$) — the number of given elements.
  * The second line contains $n$ space-separated integers of type `int`.

## Output

For each test case:
1. **First line:** The sorted elements of the input array.
2. **Second line:** Print `YES` or `NO`. In the case of a positive result (`YES`), print three space-separated 0-based indices of the found numbers after the keyword.

## Constraints & System Settings

* **Available memory:** 6 MB
* **Programming language:** C

## Example

### Input
```text
2
10
19 -3 0 4 5 1 -5 2 10 15
5
1 4 0 10 -3
```

### Output
```text
-5 -3 0 1 2 4 5 10 15 19
YES 0 0 7
-3 0 1 4 10
YES 1 1 1
```