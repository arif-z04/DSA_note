80]]]
]\
\

\
# 🔎 Binary Search Time Complexity

Binary Search works on a **sorted array**.

At every step:

* It compares the target with the **middle element**
* Then eliminates **half of the remaining elements**

---

## 📉 Why is it **O(log n)**?

Assume:

* Initial number of elements = **n**

After each step, the search space becomes half:

| Step | Remaining Elements |
| ---- | ------------------ |
| 1    | n / 2              |
| 2    | n / 4              |
| 3    | n / 8              |
| k    | n / 2ᵏ             |

We stop when only **1 element** remains:

[
\frac{n}{2^k} = 1
]

Multiply both sides by (2^k):

[
n = 2^k
]

Now take log on both sides:

[
k = \log_2 n
]

So the number of steps required = **log₂(n)**

That’s why time complexity is:

[
\boxed{O(\log n)}
]

---

# 📌 What is the base of log(n)?

For **binary search**, the base is:

[
\boxed{2}
]

Because each step divides the problem by **2**.

---

# ❓ Then why do we just write O(log n) and not O(log₂ n)?

In **Big-O notation**, we ignore constant factors.

Using log rules:

[
\log_a n = \frac{\log_b n}{\log_b a}
]

So:

[
\log_2 n = \frac{\log_{10} n}{\log_{10} 2}
]

Since (\frac{1}{\log_{10} 2}) is just a **constant**, and Big-O ignores constants:

[
O(\log_2 n) = O(\log n)
]

So the base does **not matter** in Big-O notation.

---

# 🚀 Intuition Example

If:

* n = 1,000 → log₂(1000) ≈ 10
* n = 1,000,000 → log₂(1,000,000) ≈ 20

Even if input increases 1000×, steps increase only slightly.

That’s why Binary Search is **extremely efficient**.

---

# 📊 Final Summary

| Concept               | Answer                                |
| --------------------- | ------------------------------------- |
| Worst-case complexity | O(log n)                              |
| Why?                  | Because search space halves each step |
| Log base              | 2                                     |
| Why base ignored?     | Big-O ignores constant factors        |

---
