# Linked List – Code Explanation (`template.cpp`)

This document explains every class and function defined in `template.cpp` line by line.

---

## Table of Contents
1. [Headers & Namespace](#1-headers--namespace)
2. [class Node](#2-class-node)
3. [class LinkedList](#3-class-linkedlist)
   - [Constructor](#31-constructor)
   - [push\_front](#32-push_front)
   - [push\_back](#33-push_back)
   - [insertAtPosition](#34-insertatposition)
   - [search](#35-search)
   - [pop\_front](#36-pop_front)
   - [pop\_back](#37-pop_back)
   - [deleteFromPosition](#38-deletefromposition)
   - [display](#39-display)
   - [displayWithAddress](#310-displaywithaddress)
   - [reverse](#311-reverse)
4. [main](#4-main)

---

## 1. Headers & Namespace

```cpp
#include <bits/stdc++.h>
using namespace std;
```

| Line | Explanation |
|------|-------------|
| `#include <bits/stdc++.h>` | Includes **every** standard C++ header at once (GCC extension). Brings in `<iostream>`, `<string>`, `<vector>`, etc. |
| `using namespace std;` | Allows using standard-library names (e.g. `cout`, `endl`) without the `std::` prefix. |

---

## 2. class Node

```cpp
class Node {
public:
    int data;
    Node* link;

    int id;
    static int counter;

    Node(int value) {
        data = value;
        link = NULL;

        id = ++counter;
    }
};
```

| Line | Explanation |
|------|-------------|
| `class Node {` | Declares a class called `Node`. Each object of this class represents **one element** (node) in the linked list. |
| `public:` | Everything below this keyword is accessible from outside the class. |
| `int data;` | Stores the **integer value** held by this node. |
| `Node* link;` | A pointer to the **next node** in the list. When it is `NULL` the node is the last element. |
| `int id;` | A unique serial number automatically assigned to every new node (useful for debugging). |
| `static int counter;` | A **class-level** counter (shared by all `Node` objects) that keeps track of how many nodes have been created in total. |
| `Node(int value) {` | **Constructor** — called automatically when `new Node(value)` is executed. |
| `data = value;` | Initialises `data` with the value passed to the constructor. |
| `link = NULL;` | The new node has no successor yet, so its `link` pointer is set to `NULL`. |
| `id = ++counter;` | Pre-increments the shared counter and assigns the new value as this node's unique id. |

---

## 3. class LinkedList

```cpp
class LinkedList {
private:
    Node *head;

public:
    ...
};
```

| Line | Explanation |
|------|-------------|
| `class LinkedList {` | Declares the main linked-list class that manages a chain of `Node` objects. |
| `private:` | Members below this keyword are accessible **only** from inside the class. |
| `Node *head;` | Pointer to the **first node** of the list. If `head == NULL` the list is empty. |
| `public:` | Members below this keyword are accessible from outside the class. |

---

### 3.1 Constructor

```cpp
LinkedList() {
    head = NULL;
}
```

| Line | Explanation |
|------|-------------|
| `LinkedList() {` | Default constructor — called when a `LinkedList` object is created. |
| `head = NULL;` | Sets `head` to `NULL`, meaning the list starts **empty**. |

---

### 3.2 push\_front

Inserts a new node **at the beginning** of the list.

```cpp
void push_front(int value) {
    Node *newNode = new Node(value);  // 1
    newNode->link = head;             // 2
    head = newNode;                   // 3
}
```

| Line | Explanation |
|------|-------------|
| `Node *newNode = new Node(value);` | Allocates a new `Node` on the heap with the given `value`. |
| `newNode->link = head;` | The new node's `link` is set to the current first node, so it now points to the old front of the list. |
| `head = newNode;` | Moves `head` to point to the new node, making it the new front of the list. |

**Before:** `head → [A] → [B] → NULL`  
**After `push_front(X)`:** `head → [X] → [A] → [B] → NULL`

---

### 3.3 push\_back

Inserts a new node **at the end** of the list.

```cpp
void push_back(int value) {
    Node *newNode = new Node(value);   // 1
    if (head == NULL) {                // 2
        head = newNode;
        return;
    }
    Node *temp = head;                 // 3
    while (temp->link != NULL) {       // 4
        temp = temp->link;
    }
    temp->link = newNode;              // 5
}
```

| Line | Explanation |
|------|-------------|
| `Node *newNode = new Node(value);` | Creates a new node with the given value. |
| `if (head == NULL) { head = newNode; return; }` | If the list is **empty**, the new node becomes the only element (head). |
| `Node *temp = head;` | A traversal pointer starting at the head. |
| `while (temp->link != NULL) { temp = temp->link; }` | Walk forward through the list until `temp` points to the **last node** (whose `link` is `NULL`). |
| `temp->link = newNode;` | Attaches the new node after the current last node, making it the new tail. |

---

### 3.4 insertAtPosition

Inserts a node at a **1-based** position in the list.

```cpp
void insertAtPosition(int value, int pos) {
    if (pos == 1) {                          // 1
        push_front(value);
        return;
    }
    Node *newNode = new Node(value);         // 2
    Node *temp = head;                       // 3

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {  // 4
        temp = temp->link;
    }

    if (temp == NULL) {                      // 5
        cout << "Position out of range\n";
        return;
    }

    newNode->link = temp->link;              // 6
    temp->link = newNode;                    // 7
}
```

| Line | Explanation |
|------|-------------|
| `if (pos == 1) { push_front(value); return; }` | Position 1 is the head, so delegate to `push_front` and exit. |
| `Node *newNode = new Node(value);` | Allocates the new node. |
| `Node *temp = head;` | Traversal pointer starting from the head. |
| `for (int i = 1; i < pos - 1 && temp != NULL; i++)` | Advances `temp` exactly `pos-2` steps so that it lands on the node **just before** the target position. The guard `temp != NULL` prevents going past the end. |
| `if (temp == NULL) { ... }` | If `temp` is `NULL` the requested position is beyond the list's length — print a message and return. |
| `newNode->link = temp->link;` | The new node's `link` is set to what was previously the node at position `pos`. |
| `temp->link = newNode;` | The node at position `pos-1` now points to the new node, inserting it in the correct place. |

---

### 3.5 search

Searches the list for an element and prints its 1-based position.

```cpp
void search(int item) {
    Node *temp = head;   // 1
    int pos = 1;         // 2

    while (temp != NULL) {           // 3
        if (temp->data == item) {    // 4
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->link;           // 5
        pos++;                       // 6
    }

    cout << "Not found\n";           // 7
}
```

| Line | Explanation |
|------|-------------|
| `Node *temp = head;` | Start traversal from the first node. |
| `int pos = 1;` | Position counter, starting at 1 (1-based indexing). |
| `while (temp != NULL) {` | Loop until the end of the list is reached. |
| `if (temp->data == item) { ... return; }` | If the current node's data matches `item`, print its position and exit immediately. |
| `temp = temp->link;` | Move to the next node. |
| `pos++;` | Increment the position counter. |
| `cout << "Not found\n";` | If the loop completes without finding the element, print "Not found". |

---

### 3.6 pop\_front

Removes the **first** node from the list.

```cpp
void pop_front() {
    if (head == NULL) return;   // 1
    Node* temp = head;          // 2
    head = head->link;          // 3
    delete temp;                // 4
}
```

| Line | Explanation |
|------|-------------|
| `if (head == NULL) return;` | If the list is empty there is nothing to remove — exit early. |
| `Node* temp = head;` | Save a pointer to the current head so it can be deleted later. |
| `head = head->link;` | Move `head` forward to the second node (which becomes the new first node). |
| `delete temp;` | Free the memory that was occupied by the old head node. |

---

### 3.7 pop\_back

Removes the **last** node from the list.

```cpp
void pop_back() {
    if (head == NULL) return;         // 1

    if (head->link == NULL) {         // 2
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;                // 3
    while (temp->link->link != NULL) { // 4
        temp = temp->link;
    }

    delete temp->link;                // 5
    temp->link = NULL;                // 6
}
```

| Line | Explanation |
|------|-------------|
| `if (head == NULL) return;` | Empty list — nothing to remove. |
| `if (head->link == NULL) { delete head; head = NULL; return; }` | The list has **exactly one node**: delete it and reset `head` to `NULL`. |
| `Node* temp = head;` | Traversal pointer starting at the head. |
| `while (temp->link->link != NULL) { temp = temp->link; }` | Walk forward until `temp` points to the **second-to-last** node (i.e., `temp->link` is the last node). |
| `delete temp->link;` | Delete the last node. |
| `temp->link = NULL;` | The former second-to-last node is now the tail, so its `link` is set to `NULL`. |

---

### 3.8 deleteFromPosition

Deletes the node at a **1-based** position.

```cpp
void deleteFromPosition(int pos) {
    if (head == NULL) return;   // 1

    if (pos == 1) {             // 2
        pop_front();
    }

    Node* temp = head;          // 3

    for (int i = 1; i < pos - 1 && temp->link != NULL; i++) {  // 4
        temp = temp->link;
    }
}
```

| Line | Explanation |
|------|-------------|
| `if (head == NULL) return;` | Empty list — nothing to delete. |
| `if (pos == 1) { pop_front(); }` | Deleting position 1 means removing the head, so delegate to `pop_front`. |
| `Node* temp = head;` | Traversal pointer. |
| `for (int i = 1; i < pos - 1 && temp->link != NULL; i++)` | Moves `temp` to the node just **before** the target position, while staying within bounds. |

> **Note:** The current implementation is incomplete — after finding the predecessor node it does not actually unlink and delete the target node. A complete version would require saving `temp->link`, unlinking it (`temp->link = temp->link->link`), and calling `delete` on it.

---

### 3.9 display

Prints every node's data followed by `" -> "`, ending with `"NULL"`.

```cpp
void display() {
    Node *temp = head;          // 1
    while (temp != NULL) {      // 2
        cout << temp->data << " -> ";  // 3
        temp = temp->link;      // 4
    }
    cout << "NULL\n";           // 5
}
```

| Line | Explanation |
|------|-------------|
| `Node *temp = head;` | Starts traversal at the first node. |
| `while (temp != NULL) {` | Continues until the end of the list. |
| `cout << temp->data << " -> ";` | Prints the current node's data followed by an arrow. |
| `temp = temp->link;` | Advances the pointer to the next node. |
| `cout << "NULL\n";` | Prints `NULL` to indicate the end of the list (matching the actual `NULL` `link` of the last node). |

**Example output:** `10 -> 20 -> 30 -> NULL`

---

### 3.10 displayWithAddress

Prints every node's data together with the **last 4 digits of its memory address**.

```cpp
void displayWithAddress() {
    Node *temp = head;                          // 1

    while (temp != NULL) {                      // 2
        cout << "[" << temp->data << " | "
             << (long long)temp % 10000         // 3
             << "] -> ";
        temp = temp->link;                      // 4
    }
    cout << "NULL\n";                           // 5
}
```

| Line | Explanation |
|------|-------------|
| `Node *temp = head;` | Starts at the head of the list. |
| `while (temp != NULL) {` | Loops through every node. |
| `(long long)temp % 10000` | Casts the pointer to a 64-bit integer and takes modulo 10000, giving the **last 4 digits** of the address. This is a compact way to distinguish nodes without printing the full address. |
| `temp = temp->link;` | Moves to the next node. |
| `cout << "NULL\n";` | Marks the end of the list. |

**Example output:** `[10 | 4832] -> [20 | 4896] -> NULL`

---

### 3.11 reverse

Reverses the linked list **in-place** using three pointers.

```cpp
void reverse() {
    Node* prev = NULL;   // 1
    Node* curr = head;   // 2
    Node* next;          // 3

    while (curr != NULL) {      // 4
        next = curr->link;      // 5
        curr->link = prev;      // 6
        prev = curr;            // 7
        curr = next;            // 8
    }
    head = prev;                // 9
}
```

| Line | Explanation |
|------|-------------|
| `Node* prev = NULL;` | Represents the node **behind** the current node. Starts as `NULL` because the new tail has no successor. |
| `Node* curr = head;` | The node currently being processed — starts at the head. |
| `Node* next;` | Temporary variable used to remember the node **ahead** of `curr` before we overwrite `curr->link`. |
| `while (curr != NULL) {` | Loops until every node has been reversed. |
| `next = curr->link;` | Save the next node before it is disconnected. |
| `curr->link = prev;` | Reverse the arrow: point the current node back to the previous node. |
| `prev = curr;` | Advance `prev` one step forward (it will become the "previous" for the next iteration). |
| `curr = next;` | Advance `curr` using the saved `next` pointer. |
| `head = prev;` | After the loop, `prev` is pointing to the old last node, which is now the new head. |

**Visual walk-through for `[1] → [2] → [3] → NULL`:**

| Iteration | `prev` | `curr` | `next` | List state after step 6 |
|-----------|--------|--------|--------|-------------------------|
| 1 | NULL | 1 | 2 | `NULL ← [1]   [2] → [3] → NULL` |
| 2 | 1 | 2 | 3 | `NULL ← [1] ← [2]   [3] → NULL` |
| 3 | 2 | 3 | NULL | `NULL ← [1] ← [2] ← [3]` |
| end | 3 | NULL | — | `head = 3` |

**Result:** `[3] → [2] → [1] → NULL`

---

## 4. main

```cpp
int main() {

}
```

The `main` function is currently **empty**. It serves as the entry point where you can create a `LinkedList` object and call any of the above methods to test them.

**Example usage:**

```cpp
int main() {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);
    list.display();           // 5 -> 10 -> 20 -> 30 -> NULL
    list.search(20);          // Found at position: 3
    list.reverse();
    list.display();           // 30 -> 20 -> 10 -> 5 -> NULL
    list.pop_front();
    list.pop_back();
    list.display();           // 20 -> 10 -> NULL
    return 0;
}
```
