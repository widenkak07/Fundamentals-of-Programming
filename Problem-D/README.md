# Problem D*: Aquarium (Akwarium)

An algorithmic problem involving numerical methods and root-finding without standard math libraries.

---

## 📌 Problem Description

In recent years, fishkeeping has taken over Byteotia. A specific species called *Bajtanka* has become extremely popular. Local zoologists discovered that these fish thrive best in aquariums designed with specific geometric properties:

* **Shape:** A cube with side length $k$ (in decimeters) with a rectangular section measuring $k \times (k - 1) \times 1$ cut out from one of its walls.
* **Volume:** Expressed as an integer number of decimeters cubed ($\text{dm}^3$).

Bajtolomeusz, the owner of the *Bajtankomania* pet store chain, is flooded with orders for aquariums of specified target volumes $a$. However, aquarium manufacturers require the exact side length $k$ of the cube.

### 💡 Constraints & Rules
* **No `math` library:** You **must not** use the standard library `math` functions (specifically no `sqrt`, `cbrt`, `pow`, etc.).
* **Precision:** The calculated side length $k$ must be accurate to at least $10^{-9}$. Output format requires **10 decimal places**.

---

## 🧮 Mathematical Formulation

The volume $V(k)$ of an aquarium with edge length $k$ can be modeled as:

$$V(k) = \text{Volume of cube} - \text{Volume of cut-out section}$$

$$V(k) = k^3 - \left(k \cdot (k - 1) \cdot 1\right) = k^3 - k^2 + k$$

Given a target volume $a \in \mathbb{N}$, we need to solve the cubic equation for $k$:

$$k^3 - k^2 + k - a = 0$$

Since $f(k) = k^3 - k^2 + k$ is strictly increasing for $k \ge 1$ (its derivative $f'(k) = 3k^2 - 2k + 1 > 0$ for all real $k$), there exists a unique real root $k$ for any positive volume $a$.

---

## 📥 Input Format

* The first line contains an integer $z$ ($1 \le z \le 10^7$) — the number of test cases.
* The following $z$ lines each contain a single natural number $a$ ($1 \le a \le 10^7$), representing the required volume of the aquarium in $\text{dm}^3$ (liters).

---

## 📤 Output Format

For each test case, print three values on a single line separated by spaces:
1. A floating-point number representing the approximate edge length $k$ accurate to 10 decimal places ($|k_{calc} - k_{exact}| \le 10^{-9}$).
2. $\lfloor k \rfloor$ (floor of $k$).
3. $\lceil k \rceil$ (ceiling of $k$).

---

## 📊 Example

### Input
```text
8
1
6
10
64
100
4957
2748
3193
```

### Output
```text
1.0000000000 1 1
2.0000000000 2 2
2.3650189946 2 3
4.2722976594 4 5
4.9229913962 4 5
17.3706017009 17 18
14.3238264459 14 15
15.0432163201 15 16
```

---

## 🛠️ Recommended Algorithms

Since standard mathematical root-finding functions like `sqrt` or `cbrt` are strictly prohibited, consider using:
1. **Binary Search on Answer** (Bisection method over floating-point ranges).
2. **Newton-Raphson Method**:
   $$k_{n+1} = k_n - \frac{k_n^3 - k_n^2 + k_n - a}{3k_n^2 - 2k_n + 1}$$