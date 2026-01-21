# Data Structure and Algorithm

This is my personal note. I tried my best to include everything I learned through my DSA classes. Hopefully this note will cover up everything. Peace! 

``PS: This note is based on Schaums Outline Series Book and my own learnings.``

---
# Table of Contents
- [Intro](#️-intro)
- [Complexity Analysis](#--complexity-analysis-time--space)
- [Preliminaries](#️-preliminaries)
- [String Processing](#string-processing)
- [Arrays]()
- [Pointers]()
- [Linked Lists]()
- [Stack]()
- [Queue]()
- [Recursion]()
- [Trees]()
- [Graphs]()

---
## ⛩️ Intro

>A data structure is a particular way of organizing data in a computer so that it can be used effectively. The idea is to reduce the space and time complexities of different tasks. Here are some common data structure:
- Arrays
- Linked Lists
- Stack
- Queues
- Trees
- Graphs
- Hash Tables
  
### Abstract Data Types

>An abstract data type (ADT) is an abstraction of a data structure which provides only the interface to which a data structure must adhere to. Ther interface does not give any specific details about how something should be implemented or in what programming language.

---


## ⏰ 💻 Complexity Analysis (Time & Space)

In **computer science**, complexity analysis helps us understand **how efficient an algorithm is** in terms of:

1. **Time Complexity** → How much time an algorithm takes
2. **Space Complexity** → How much memory an algorithm uses

We usually analyze complexity using **Big-O notation**.



## 1. Time Complexity

Time complexity measures how the **execution time grows with input size (n)**.

### Common Time Complexities

| Notation       | Name         | Example                          |
| -------------- | ------------ | -------------------------------- |
| **O(1)**       | Constant     | Accessing an array element       |
| **O(log n)**   | Logarithmic  | Binary search                    |
| **O(n)**       | Linear       | Traversing an array              |
| **O(n log n)** | Linearithmic | Merge sort                       |
| **O(n²)**      | Quadratic    | Nested loops                     |
| **O(2ⁿ)**      | Exponential  | Recursive Fibonacci              |
| **O(n!)**      | Factorial    | Traveling Salesman (brute force) |

---

### Example 1: Linear Time

```c
for(int i = 0; i < n; i++)
    printf("%d", i);
```

⏱ **Time Complexity:** `O(n)`

---

### Example 2: Nested Loop

```c
for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++)
    printf("*");
```

⏱ **Time Complexity:** `O(n²)`

---

### Best, Average & Worst Case

| Case        | Meaning       |
| ----------- | ------------- |
| **Best**    | Minimum time  |
| **Average** | Expected time |
| **Worst**   | Maximum time  |

📌 Example: **Linear Search**

* Best: `O(1)`
* Worst: `O(n)`
* Average: `O(n)`

---

## 2. Space Complexity

Space complexity measures **extra memory used** by the algorithm.

### Components:

1. **Input Space**
2. **Auxiliary Space** (temporary variables, recursion stack)

---

### Example: Constant Space

```c
int sum(int a, int b) {
    return a + b;
}
```

🧠 **Space Complexity:** `O(1)`

---

### Example: Linear Space

```c
int arr[n];
```

🧠 **Space Complexity:** `O(n)`

---

### Recursion Example

```c
int fact(int n){
    if(n == 0) return 1;
    return n * fact(n - 1);
}
```

🧠 **Space Complexity:** `O(n)` (recursive call stack)

---

## 3. Big-O, Big-Ω, Big-Θ

| Notation      | Meaning                    |
| ------------- | -------------------------- |
| **Big-O (O)** | Upper bound (worst case)   |
| **Big-Ω (Ω)** | Lower bound (best case)    |
| **Big-Θ (Θ)** | Tight bound (exact growth) |

---

## 4. How to Analyze Complexity (Steps)

1. Ignore constants
2. Ignore lower-order terms
3. Focus on the fastest-growing term

Example:

```
T(n) = 3n² + 5n + 7 → O(n²)
```

---

## 5. Why Complexity Analysis is Important?

✔ Compare algorithms

✔ Predict performance

✔ Optimize code

✔ Essential for competitive programming & interviews

---
## :spiral_notepad: Preliminaries 

📌 Chapter 2: `2.3` `Algorithm Notation`

### 2.1 Largest Element in array
```cpp
#include <iostream>
using namespace std;

void LargestElementArray(int DATA[], int N){
    int K = 0, LOC = 0, MAX = DATA[0];

increment_counter:
    K = K + 1;
    if(K == N){
        cout << "LOC = " << LOC << ", MAX = " << MAX << "\n";
        return;
    }
    if (MAX < DATA[K])
    {
        LOC = K;
        MAX = DATA[K];
    }
    goto increment_counter;
}

int main()
{
    int DATA[] = {3, 5, 9, 2};
    int N = sizeof(DATA) / sizeof(int);
    LargestElementInArray(DATA, N);
    return 0;
}

```

Alternate Solution:
```cpp
#include <bits/stdc++.h>
using namespace std;

void LargestElementArray(int data[], int n){
    int mx = data[0];
    int loc = 0;
    for(int i = 0; i < n; i++){
        if(data[i] > mx){
            mx = data[i];
            loc = i;
        }
    }
    cout << "LOC = " << loc << ", MAX = " << mx << endl;
}

int main(){
    int arr[] = {3, 5, 9, 8};
    int n = sizeof(arr)/sizeof(int);
    LargestElementArray(arr, n);

    return 0;
}
```
---
### 2.2 Quadratic equation

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int D = B * B - 4 * A * C;
    if (D > 0)
    {
        float X1 = (-B + sqrt(D)) / (2 * A);
        float X2 = (-B - sqrt(D)) / (2 * A);
        cout << X1 << " and " << X2 << "\n";
    }
    else if (D == 0)
    {
        float X = -B / 2 * A;
        cout << "UNIQUE SOLUTION : " << X << "\n";
    }
    else 
    {
        cout << "NO REAL SOLUTIONS" << "\n";
    }
    return 0;
}
```
---

## String Processing

**What is a string?**
> A finite sequence of characters called a string.  

