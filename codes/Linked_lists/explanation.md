# LinkedList Class: Line-by-Line Explanation

This file explains all functions inside the `LinkedList` class from `template.cpp`.
The list is a **singly linked list**, where each node has `data` and a pointer `link` to the next node.

## 1) Constructor: `LinkedList()`

```cpp
LinkedList(){
    head = NULL;
}
```

Line-by-line:
1. `LinkedList(){`
   Defines the constructor of the `LinkedList` class. It runs automatically when an object of `LinkedList` is created.
2. `head = NULL;`
   Sets the starting pointer of the list to `NULL`, meaning the list is initially empty.
3. `}`
   Ends the constructor.

## 2) `push_front(int value)`

```cpp
void push_front(int value){
    Node *newNode = new Node(value);
    newNode->link = head;
    head = newNode;
}
```

Line-by-line:
1. `void push_front(int value){`
   Declares a function to insert a new node at the beginning of the list.
2. `Node *newNode = new Node(value);`
   Dynamically creates a new node with the given `value`.
3. `newNode->link = head;`
   Makes the new node point to the current first node.
4. `head = newNode;`
   Updates `head` so the new node becomes the first node.
5. `}`
   Ends the function.

## 3) `push_back(int value)`

```cpp
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
```

Line-by-line:
1. `void push_back(int value){`
   Declares a function to insert a new node at the end of the list.
2. `Node *newNode = new Node(value);`
   Creates a new node with the provided value.
3. `if(head == NULL){`
   Checks whether the list is empty.
4. `head = newNode;`
   If empty, the new node becomes the first node.
5. `return;`
   Stops function execution because insertion is complete.
6. `}`
   Ends the `if` block.
7. `Node *temp = head;`
   Creates a temporary pointer to traverse from the head.
8. `while(temp->link != NULL){`
   Moves forward until the last node (whose `link` is `NULL`) is found.
9. `temp = temp->link;`
   Advances `temp` to the next node.
10. `}`
    Ends the traversal loop.
11. `temp->link = newNode;`
    Connects the last node to the new node.
12. `}`
    Ends the function.

## 4) `insertAtPosition(int value, int pos)`

```cpp
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

Line-by-line:
1. `void insertAtPosition(int value, int pos){`
   Declares a function to insert a node at a given 1-based position.
2. `if(pos == 1){`
   Checks if insertion is requested at the first position.
3. `push_front(value);`
   Reuses the front insertion function to insert at position 1.
4. `return;`
   Ends the function since insertion is done.
5. `}`
   Ends the `if` block.
6. `Node *newNode = new Node(value);`
   Creates a new node to insert.
7. `Node *temp = head;`
   Starts traversal from the head.
8. `for(int i = 1; i < pos - 1 && temp != NULL; i++){
`
   Runs up to the node just before target position, while ensuring `temp` is valid.
9. `temp = temp->link;`
   Moves one step forward.
10. `}`
    Ends loop.
11. `if(temp == NULL){`
    If traversal failed (position is beyond list length), insertion is invalid.
12. `cout << "Position out of range\n";`
    Prints an error message.
13. `return;`
    Exits without inserting.
14. `}`
    Ends range-check block.
15. `newNode->link = temp->link;`
    Makes new node point to the node currently after `temp`.
16. `temp->link = newNode;`
    Makes `temp` point to new node, completing insertion.
17. `}`
    Ends the function.

## 5) `search(int item)`

```cpp
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
```

Line-by-line:
1. `void search(int item){`
   Declares a function to find a value in the list.
2. `Node *temp = head;`
   Starts searching from the first node.
3. `int pos = 1;`
   Keeps track of 1-based position.
4. `while(temp != NULL){`
   Continues until all nodes are checked.
5. `if(temp->data == item){`
   Compares current node value with target item.
6. `cout << "Found at position: " << pos << endl;`
   Prints the position if found.
7. `return;`
   Stops searching immediately.
8. `}`
   Ends `if` block.
9. `temp = temp->link;`
   Moves to next node.
10. `pos++;`
    Increments position counter.
11. `}`
    Ends loop.
12. `cout << "Not found\n";`
    If loop ends normally, item does not exist in list.
13. `}`
    Ends the function.

## 6) `pop_front()`

```cpp
void pop_front(){
    if(head == NULL) return;
    Node* temp = head;
    head = head->link;
    delete temp;
}
```

Line-by-line:
1. `void pop_front(){`
   Declares a function to remove the first node.
2. `if(head == NULL) return;`
   If list is empty, there is nothing to delete.
3. `Node* temp = head;`
   Stores current head node in a temporary pointer.
4. `head = head->link;`
   Moves head to second node.
5. `delete temp;`
   Frees memory of the old first node.
6. `}`
   Ends the function.

## 7) `display()`

```cpp
void display(){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->link;
    }

    cout << "NULL\n";
}
```

Line-by-line:
1. `void display(){`
   Declares a function to print list values in sequence.
2. `Node *temp = head;`
   Starts traversal from head.
3. `while(temp != NULL){`
   Loops through each node.
4. `cout << temp->data << " -> ";`
   Prints current node value followed by arrow.
5. `temp = temp->link;`
   Moves to next node.
6. `}`
   Ends loop.
7. `cout << "NULL\n";`
   Prints `NULL` to indicate end of list.
8. `}`
   Ends function.

## 8) `displayWithAddress()`

```cpp
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
```

Line-by-line:
1. `void displayWithAddress()`
   Declares a function to print node data with a short address hint.
2. `{`
   Starts function body.
3. `Node *temp = head;`
   Starts traversal from first node.
4. `while (temp != NULL)`
   Traverses until end of list.
5. `{`
   Starts loop body.
6. `cout << "[" << temp->data << " | " << (long long)temp % 10000 << "] -> ";`
   Prints node data and reduced numeric form of node address (`temp % 10000`) for easy visualization.
7. `temp = temp->link;`
   Moves to next node.
8. `}`
   Ends loop.
9. `cout << "NULL\n";`
   Prints end marker.
10. `}`
    Ends function.

## Quick Notes

1. `push_front` is `O(1)`.
2. `push_back` is `O(n)` in this implementation (no tail pointer).
3. `search` is `O(n)`.
4. `insertAtPosition` is `O(n)` due to traversal.
5. `pop_front` is `O(1)`.
6. `display` and `displayWithAddress` are `O(n)`.
