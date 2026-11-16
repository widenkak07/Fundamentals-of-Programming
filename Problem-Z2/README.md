# Problem Z2: Miss School (Miss szkoły)

An algorithmic challenge focused on frequency counting, case-insensitive string handling, and custom sorting using **Shell sort**.

## 📖 Problem Description

On the occasion of the annual School Naming Day, a "Miss School" beauty pageant was organized. For an entire week, students could drop the names of their chosen candidates into prepared ballot boxes. 

Your task is to write a program that counts how many votes each candidate received and prepares the final voting ranking.

## 📥 Input

* The first line contains an integer $z$ ($1 \le z \le 10^9$) — the number of test cases that follow.
* For each test case:
  * The first line contains a single natural number $n$ ($1 \le n \le 20\,000$), denoting the number of strings (votes) to be processed.
  * The second line contains $n$ space-separated strings, each of maximum length $1\,000$. The strings consist exclusively of English alphabet letters.

## 📤 Output

For each test case, output the competition ranking:
* The first line should contain a natural number $k$, representing the total number of unique candidates.
* Each of the following $k$ lines should contain a candidate's name followed by a space and the number of votes she received.
* **Sorting criteria:**
  1. Candidates must be listed in **descending order** by the number of votes received.
  2. In case of a tie (the same number of votes), candidates must be listed in **alphabetical order** (case-insensitive).
* *Note:* Letter casing in the candidates' names does not matter (e.g., `Frania` and `frania` count as the same candidate, and any valid casing from the input/normalized form is accepted in the output).

## ⚠️ Technical Constraints

* **Required Algorithm:** The problem **MUST** be solved using **Shell sort**.
* **Case Sensitivity:** Comparisons and vote grouping must be completely case-insensitive.

## 💡 Example

### Input
```text
2
14
frania jola iga kasia Gosia frania Agata ala jola Iga gosia Kasia Gosia Frania
15
j h g f e c C b A j h g f h G
```

### Output
```text
7
Frania 3
Gosia 3
iga 2
jola 2
Kasia 2
Agata 1
ala 1
8
G 3
h 3
C 2
f 2
j 2
A 1
b 1
e 1
```

## 🛠️ Compilation & Usage

Example compilation and execution (assuming C/C++ implementation):

```bash
gcc -O2 -Wall -Wextra solution.c -o solution
./solution < input.txt
```