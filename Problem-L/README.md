# Problem L*: Christmas Chain (Świąteczny łańcuch)

A C programming challenge focused on pointer arithmetic and subsequence matching without using standard array subscripting operators.

## 📖 Problem Description

In Byteotia, keyboards look a bit different from what you are used to. One of the main differences is the complete absence of the `[` and `]` keys. 

Whenever a human candidate applies to the Byteotian company *BajtoLand*, one of the key stages of the technical interview is testing their ability to handle arrays without using square brackets (`[` and `]`). The candidate is asked to solve the following problem:

Christmas is approaching! Marysia wants to buy a colorful garland (chain) to hang on her mother's Christmas tree. She has a clear vision of what the chain should look like, but unfortunately, none of the chains available in the store match her exact expectations. 

Marysia decides to buy the chain that is closest to her ideal design and modify it slightly by removing the elements she doesn't like. Your task is to help Marysia determine whether her dream Christmas decorations can be created from the purchased chain by removing zero or more elements.

## 📥 Input

* The first line contains an integer $z$ ($1 \le z \le 2 \cdot 10^9$) — the number of test cases that follow.
* For each test case:
  * The first line contains a single integer $m$ ($1 \le m \le 1\,000\,000$), representing the length of the purchased chain.
  * The second line contains $m$ integers $a_1, a_2, \dots, a_m$ ($1 \le a_i \le 1\,000\,000$), describing the elements of the chain Marysia bought.
  * The third line contains a positive integer $n$, representing the number of dream chains Marysia wants to check.
  * The following lines contain descriptions of $n$ target chains. Each description consists of two lines:
    * The first line contains an integer $m_i$ ($1 \le m_i \le 1\,000\,000$).
    * The second line contains a sequence of $m_i$ integers $b_{i1}, b_{i2}, \dots, b_{im_i}$ ($1 \le b_{ij} \le 1\,000\,000$ for $1 \le j \le m_i$).
  * *Note:* You may assume that the sum of lengths $m_i$ of all $n$ sequences in a test case does not exceed $1\,000\,000$.

## 📤 Output

For each of the $n$ target chains in a test case, output a single word: `YES` if Marysia's dream chain can be formed by removing some (not necessarily contiguous) elements from the initial chain, or `NO` otherwise.

* **Allowed operation:** Removing a chosen element from the chain (can be applied multiple times).
* **Constraints on order:** The relative order of the remaining elements must match their original order in the purchased chain. Swapping elements or moving a removed element to another position is not allowed.

## ⚠️ Technical Constraints

* **Forbidden characters:** You **MUST NOT** use `[` or `]` anywhere in your source code (including comments!).
* **Language:** C
* **Memory limit:** 8–64 MB (depending on the test case)

## 💡 Example

### Input
```text
1
7
1 5 4 5 7 8 6
4
5
1 5 5 8 6
3
2 2 2
3
5 7 8
4
1 5 7 4
```

### Output
```text
YES
NO
YES
NO
```

## 🛠️ Compilation & Usage

Since array indexing with `[]` is forbidden, ensure your solution uses pointer arithmetic (`*(ptr + i)`) and dynamic memory allocation (`malloc` / `free`).

```bash
gcc -O2 -Wall -Wextra solution.c -o solution
./solution < input.txt
```