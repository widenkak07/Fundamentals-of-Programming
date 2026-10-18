# Task C1: Tree Removal for Hypermarket Construction

This repository contains a solution in C for **Task C1**.

## Problem Description

Determine the number of trees that need to be cut down for the construction of a hypermarket. The hypermarket will be located at the beginning of the street, stretching from its western end up to the $a$-th meter. All trees located at most $a$ meters along the road must be removed.

### Input Structure

* The first line contains an integer $z$ ($1 \le z \le 10^7$), representing the number of test cases.
* Each test case is described as follows:
  * **Line 1:** An integer $k$ ($1 \le k \le 10^6$) — the number of chestnut trees.
  * **Line 2:** $k$ space-separated natural numbers. The first number is the position (distance in meters) of the first chestnut tree along the street. Each subsequent number represents the distance in meters between consecutive trees. No individual value exceeds $2 \cdot 10^3$.
  * **Line 3:** An integer $q$ ($1 \le q \le 10^6$) — the number of queries for this test case.
  * **Next $q$ lines:** Each line contains a single integer $a$ ($0 \le a \le 2 \cdot 10^9$).

### Output Structure

For each test case, output $q$ lines. Each line should contain a single integer: the number of trees that must be cut down for the hypermarket construction up to meter $a$.

### Constraints & Details

* **Available memory:** 8 MB
* **Programming language:** C