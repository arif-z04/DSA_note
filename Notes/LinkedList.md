# Linked List কী ?
Linked List হচ্ছে একটা Data Structure যা Node গুলোর একটা সিরিজ। প্রতিটা Node-এ থাকে একটা Data আর একটা Pointer যা পরের Node কে ধরে। 

```text
+------+------+
| data | link |
+------+------+
```


## Visual Repressentation:
```text
head
 |
 v
+----+------+    +----+------+    +----+------+
| 10 |  *---|--->| 20 |  *---|--->| 30 | NULL |
+----+------+    +----+------+    +----+------+
```


# Template: (এটা কপি করে তোমার IDE তে লিখে দেখতে পারো)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* link;

    // int id;
    // static int counter;

    Node(int value){
        data = value;
        link = NULL;

        // id = ++counter;
    }
};

class LinkedList
{
private:
    Node *head;

public: 
    LinkedList(){
        head = NULL;
    }
    void push_front(int value){
        Node *newNode = new Node(value);
        newNode->link = head;
        head = newNode;
    }
    void push_back(int value){
        Node *newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;
    }
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
    // Search element
    void search(int item){
        Node *temp = head;
        int pos = 1;

        while(temp != NULL){
            if(temp->data == item){
                cout << "Found at position: " << pos << endl;
                return;
            }
            temp = temp->link;
            pos++;
        }

        cout << "Not found\n";
    }

    void pop_front(){
        if(head == NULL) return;
        Node* temp = head;
        head = head->link;
        delete temp;
    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->link;
        }

        cout << "NULL\n";
    }
    // display with address
    void displayWithAddress()
    {
        Node *temp = head;

        while (temp != NULL)
        {

            cout << "[" << temp->data << " | " << (long long)temp % 10000 << "] -> ";
            temp = temp->link;
        }
        cout << "NULL\n";
    }


};

int main(){

}

``` 


# প্রথমে Node টা বুঝি

```cpp
class Node{
public:
    int data;
    Node* link;

    Node(int value){
        data = value;
        link = NULL;
    }
};
```

একটা Node দেখতে এমন:

```text
+------+------+
| data | link |
+------+------+
```

ধরো:

```cpp
Node* n1 = new Node(10);
```

Memory:

```text
Address: 1000

+------+------+
|  10  | NULL |
+------+------+
```

---

## Constructor কী করছে?

```cpp
Node(int value){
    data = value;
    link = NULL;
}
```

যখন লিখি

```cpp
Node* n1 = new Node(10);
```

তখন ভিতরে automatic চলে:

```cpp
data = 10;
link = NULL;
```

---

# Step 2: LinkedList Class

```cpp
class LinkedList
{
private:
    Node *head;
```

head হচ্ছে পুরো Linked List-এর entry point।

ধরো List:

```text
10 -> 20 -> 30 -> NULL
```

তখন

```text
head
 |
 v
10 -> 20 -> 30 -> NULL
```

head হারিয়ে গেলে পুরো list হারিয়ে যাবে।

---

# Constructor

```cpp
LinkedList(){
    head = NULL;
}
```

শুরুতে List খালি।

```text
head
 |
NULL
```

---

# List তৈরি

main এ:

```cpp
int main()
{
    LinkedList list;
}
```

তখন

```text
head -> NULL
```

List empty.

---

# push_front()

```cpp
void push_front(int value)
{
    Node *newNode = new Node(value);

    newNode->link = head;

    head = newNode;
}
```

---

## Example

```cpp
list.push_front(10);
```

### Step 1

```cpp
Node *newNode = new Node(10);
```

Memory:

```text
1000

+----+------+
| 10 | NULL |
+----+------+
```

---

### Step 2

```cpp
newNode->link = head;
```

head এখন NULL

তাই

```text
10 -> NULL
```

---

### Step 3

```cpp
head = newNode;
```

```text
head
 |
 v
10 -> NULL
```

---

## আবার

```cpp
list.push_front(20);
```

---

নতুন Node:

```text
20 -> NULL
```

---

```cpp
newNode->link = head;
```

মানে:

```text
20 -> 10 -> NULL
```

---

```cpp
head = newNode;
```

Result:

```text
head
 |
20 -> 10 -> NULL
```

---

# push_back()

```cpp
void push_back(int value)
```

List-এর শেষে insert করে।

---

ধরো:

```cpp
list.push_back(10);
list.push_back(20);
list.push_back(30);
```

---

## First Insert

```text
head
 |
10 -> NULL
```

---

## Second Insert

temp head থেকে শুরু করে।

```cpp
Node *temp = head;
```

```text
temp
 |
10 -> NULL
```

---

Loop:

```cpp
while(temp->link != NULL)
{
    temp = temp->link;
}
```

10 এর link NULL

তাই loop বন্ধ।

---

```cpp
temp->link = newNode;
```

```text
10 -> 20 -> NULL
```

---

## Third Insert

Loop চলবে

```text
temp
 |
10 -> 20 -> NULL
```

---

1st iteration:

```text
temp
      |
      20
```

---

20 এর next NULL

Loop stop

---

```cpp
temp->link = newNode;
```

Result:

```text
10 -> 20 -> 30 -> NULL
```

---

# display()

```cpp
void display()
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->link;
    }

    cout << "NULL\n";
}
```

---

ধরো:

```text
10 -> 20 -> 30 -> NULL
```

---

শুরু

```text
temp
 |
10
```

Print:

```text
10 ->
```

---

Move

```cpp
temp = temp->link;
```

```text
temp
 |
20
```

Print:

```text
20 ->
```

---

Move

```text
temp
 |
30
```

Print:

```text
30 ->
```

---

Move

```text
temp = NULL
```

Loop শেষ।

Output:

```text
10 -> 20 -> 30 -> NULL
```

---

# displayWithAddress()

এটা Linked List শেখার জন্য অসাধারণ।

```cpp
cout << "[" << temp->data
     << " | "
     << (long long)temp % 10000
     << "] -> ";
```

---

ধরো Memory:

```text
Node(10) = address 5240

Node(20) = address 8150

Node(30) = address 3220
```

Output:

```text
[10 | 5240] ->
[20 | 8150] ->
[30 | 3220] ->
NULL
```

এতে বোঝা যায় Node গুলো memory-তে পাশাপাশি নেই।

Array:

```text
1000
1004
1008
1012
```

Linked List:

```text
5240
8150
3220
9001
```

Random address।

---

# insertAtPosition()

ধরো:

```text
10 -> 20 -> 30 -> NULL
```

Insert:

```cpp
insertAtPosition(15,2);
```

Result চাই:

```text
10 -> 15 -> 20 -> 30
```

---

## Step 1

```cpp
Node *newNode = new Node(15);
```

```text
15 -> NULL
```

---

## Step 2

```cpp
Node *temp = head;
```

```text
temp
 |
10
```

---

## Loop

```cpp
for(int i=1;i<pos-1;i++)
```

এখানে

```text
pos = 2
```

তাই loop চলবে না।

temp থাকবে 10 এর উপর।

---

## Linking

```cpp
newNode->link = temp->link;
```

```text
15 -> 20
```

---

```cpp
temp->link = newNode;
```

```text
10 -> 15 -> 20 -> 30
```

---

# search()

```cpp
list.search(20);
```

---

শুরু:

```text
temp -> 10
pos = 1
```

10 ≠ 20

---

Move

```text
temp -> 20
pos = 2
```

---

Match

```cpp
cout << "Found at position: 2";
```

---

# pop_front()

ধরো:

```text
head
 |
10 -> 20 -> 30
```

---

```cpp
Node* temp = head;
```

```text
temp
 |
10
```

---

```cpp
head = head->link;
```

```text
head
 |
20 -> 30
```

---

```cpp
delete temp;
```

10 memory থেকে delete।

Result:

```text
20 -> 30
```

---

# Template ব্যবহার করার Full Example

```cpp
int main()
{
    LinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.display();

    list.push_front(5);

    list.display();

    list.insertAtPosition(15,3);

    list.display();

    list.search(20);

    list.pop_front();

    list.display();

    list.displayWithAddress();
}
```

Output:

```text
10 -> 20 -> 30 -> NULL

5 -> 10 -> 20 -> 30 -> NULL

5 -> 10 -> 15 -> 20 -> 30 -> NULL

Found at position: 4

10 -> 15 -> 20 -> 30 -> NULL

[10 | 5240] ->
[15 | 8150] ->
[20 | 3220] ->
[30 | 9001] ->
NULL
```

---

## সবচেয়ে গুরুত্বপূর্ণ Concept

Linked List-এর পুরো জিনিসটা এই দুই লাইনের উপর দাঁড়িয়ে আছে:

```cpp
Node* head;
Node* link;
```

* `head` → প্রথম Node কে ধরে।
* `link` → পরের Node কে ধরে।

Visual:

```text
head
 |
 v
+----+------+     +----+------+     +----+------+
| 10 |  *---|---->| 20 |  *---|---->| 30 | NULL |
+----+------+     +----+------+     +----+------+
```

যেদিন তুমি Pointer-এর এই arrow (`->`) movement পুরোপুরি visualize করতে পারবে, সেদিন Linked List তোমার কাছে খুবই সহজ মনে হবে।
