
## 1. What is Data Structure? Explain Data Structure Operations.

### ✅ Definition of Data Structure

A **Data Structure** is a particular way of organizing and storing data in a computer so that it can be used efficiently.

It represents the logical or mathematical model of a particular organization of data.

In simple words:

> A data structure is a collection of data elements organized in a specific way to perform operations efficiently.

Examples:

* Arrays
* Linked Lists
* Stacks
* Queues
* Trees
* Graphs

---

### ✅ Operations on Data Structures

According to the book, the basic operations that can be performed on data structures are:

1. **Traversal**
   
   Visiting each element of the data structure exactly once.

2. **Insertion**
   
   Adding a new element to the structure at a specified location.

3. **Deletion**
   
   Removing an element from the structure.

4. **Searching**
   
   Finding the location of a given element.

5. **Sorting**
   
   Arranging elements in a particular order (ascending/descending).

6. **Merging**
   
   Combining two data structures into one.

---

## 2. What is Complexity?

### ✅ Definition of Complexity

**Complexity** refers to the amount of resources (mainly time and space) required by an algorithm to execute.

There are two types:

1. **Time Complexity**
   Measures the time required to run an algorithm as a function of input size ( n ).

2. **Space Complexity**
   Measures the memory required by the algorithm.

Complexity is usually expressed using **Big-O notation**, such as:

* ( O(1) )
* ( O(n) )
* ( O(\log n) )
* ( O(n^2) )

---

## 3. Explain Time Complexity of Linear Search

### ✅ Linear Search

Linear search checks each element one by one until the desired element is found or the list ends.

If there are ( n ) elements:

* **Best Case:**
  Element found at first position
  👉 ( O(1) )

* **Worst Case:**
  Element found at last position or not found
  👉 ( O(n) )

* **Average Case:**
  Element found somewhere in the middle
  👉 ( O(n) )

### 🔹 Conclusion:

Time complexity of Linear Search is:
[
O(n)
]

---

## 4. Explain Time Complexity of Binary Search

### ✅ Binary Search

Binary search works only on a **sorted list**.

Steps:

1. Compare target with middle element.
2. If equal → found.
3. If smaller → search left half.
4. If larger → search right half.
5. Repeat.

Each step halves the search space.

If there are ( n ) elements:

Number of comparisons ≈
[
\log_2 n
]

* **Best Case:**
  Element found at middle
  👉 ( O(1) )

* **Worst Case:**
  👉 ( O(\log n) )

* **Average Case:**
  👉 ( O(\log n) )

### 🔹 Conclusion:

Time complexity of Binary Search is:
[
O(\log n)
]

---

## 5. Compare Complexity of Linear Search and Binary Search

| Feature      | Linear Search                   | Binary Search            |
| ------------ | ------------------------------- | ------------------------ |
| Requirement  | Works on sorted & unsorted list | Requires sorted list     |
| Best Case    | ( O(1) )                        | ( O(1) )                 |
| Worst Case   | ( O(n) )                        | ( O(\log n) )            |
| Average Case | ( O(n) )                        | ( O(\log n) )            |
| Efficiency   | Slow for large data             | Very fast for large data |

### 🔹 Main Difference

For large ( n ):

* Linear Search → grows proportionally to ( n )
* Binary Search → grows proportionally to ( \log n )

Example:
If ( n = 1,000,000 )

* Linear Search → up to 1,000,000 comparisons
* Binary Search → about 20 comparisons

 Therefore, Binary Search is much more efficient for large sorted data.

---

