# Chapter 5: Linked List

## What is a Linked List?

A **_linked list_** is a linear data structure where elements (called nodes) are stored in a **non-contiguous memory**, and each node is connected to the next one using a pointer (or link).

## Structure of a Node

Each node has two parts:
1. Data: Store the value
2. Pointer (or link): Stores the address of the next node

```
[Data | Next] → [Data | Next] → [Data | Next] → NULL
```

## 5.4 Traversing a Linked List

To traverse a linked list, you start from the head node and follow the pointers until you reach the end (NULL).

```Cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void traverse() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;    
        }
        cout << "NULL" << endl; 
    }
};

```
Input:
```cpp
int main() {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.traverse();
    return 0;
}
```
Output:
```
10 -> 20 -> 30 -> NULL
```

## Example: 5.7 Counting the number of elements in a linked list

```Cpp
int countElements() {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
```

## 5.5 Searching
To search for an element in a linked list, you can traverse the list and compare each node's data with the target value.


```Cpp
Node* search(int item) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return NULL; // List is empty
    }

    Node* current = head;
    while (current != NULL) {
        if (current->data == item) {
            return current; // Item found
        }
        current = current->next;
    }
    return NULL; // Item not found
}
```
Input:
```cpp
int main() {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    Node* foundNode = list.search(20);
    if (foundNode != NULL) {
        cout << "Element found: " << foundNode->data << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}
```

Output:
```
Element found: 20
```

## 5.5 Searching in a sorted linked list
If the linked list is sorted, you can optimize the search by stopping once you encounter a node with a value greater than the target item.

```Cpp
Node* searchSorted(int item) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return NULL; // List is empty
    }
    Node* current = head;
    while (current != NULL) {
        if (current->data < item) {
            current = current->next; // Continue searching
        } else if (current->data == item) {
            return current; // Item found
        } else {
            break; // No need to continue, item not found
        } 
    }
    return NULL; // Item not found
}
```
Input:
```cpp
int main() {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    Node* foundNode = list.searchSorted(25);
    if (foundNode != NULL) {
        cout << "Element found: " << foundNode->data << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}
```
Output:
```
Element not found.
```

## 5.6 Memory Allocation and Garbage Collection

**Memory Allocation:**
The process of assigning memory toa a program or variable during execution.
Types:
1. Static Allocation: Memory is allocated at compile time (e.g., arrays).
2. Dynamic Allocation: Memory is allocated at runtime (e.g., linked lists using `new Node()`).

**Garbage Collection:**
The process of automatically freeing memory that is no longer in use by the program.

Example:
```cpp
void deleteList() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp; // Free memory
    }
    head = NULL; // List is now empty
}   
``` 
Input:
```cpp
int main() {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.deleteList();
    list.traverse(); // Should indicate the list is empty
    return 0;
}
```
Output:
```
List is empty.
``` 

## 5.7 Insertion into a Linked List
To insert a new node into a linked list, you can use the following methods:

1. **Insertion at the beginning**: Create a new node and make it the new head of the list.

Algorithm **5.4**
```Cpp
void push_front(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
```
Input:
```cpp
int main() {
    LinkedList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.traverse();
    return 0;
}
```
Output:
```
30 -> 20 -> 10 -> NULL
``` 

2. **Insertion at the end**: Create a new node and link it to the last node of the list.

```Cpp
void push_back(int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
```
Input:
```cpp
int main() {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.traverse();
    return 0;
}
```
Output:
```
10 -> 20 -> 30 -> NULL
```     
3. **Insertion at a specific position**: Create a new node and insert it at the desired position in the list.

Algorithm **5.5**

```Cpp
// Insert at position 1-based
void insertAtPosition(int value, int pos){
    if(pos == 1){
        push_front(value);
        return;
    }
    Node *newNode = new Node(value);
    Node *temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->link;
    }

    if(temp == NULL){
        cout << "Position out of range\n";
        return;
    }

    newNode->link = temp->link;
    temp->link = newNode;
}
```
Input:
```cpp
int main() {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.insertAtPosition(15, 2); // Insert 15 at position 2
    list.traverse();
    return 0;
}
```
Output:
```
10 -> 15 -> 20 -> 30 -> NULL
``` 


