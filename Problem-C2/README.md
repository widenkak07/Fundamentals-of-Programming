# Task C2: Tree Removal for Road Construction

This repository contains a solution in C for **Task C2**.

## Problem Description

Determine the number of trees that need to be cut down for the construction of a new road. The new road will intersect Kasztanowa Street at a right angle, between the $a$-th and $b$-th meters. All trees located at least at the $a$-th meter and at most at the $b$-th meter must be removed.

### Input Structure

* The first line contains an integer $z$ ($1 \le z \le 10^7$), representing the number of test cases.
* Each test case is described as follows:
  * **Line 1:** An integer $k$ ($1 \le k \le 10^6$) — the number of chestnut trees.
  * **Line 2:** $k$ space-separated natural numbers. The first number is the position (distance in meters) of the first chestnut tree along the street. Each subsequent number represents the distance in meters between consecutive trees. No individual value exceeds $2 \cdot 10^3$.
  * **Line 3:** An integer $q$ ($1 \le q \le 10^6$) — the number of queries for this test case.
  * **Next $q$ lines:** Each line contains two integers $a, b$ ($0 \le a \le b \le 2 \cdot 10^9$).

### Output Structure

For each test case, output $q$ lines. Each line should contain a single integer: the number of trees that must be cut down for the road construction between meters $a$ and $b$.

### Constraints & Details

* **Available memory:** 8 MB
* **Programming language:** C