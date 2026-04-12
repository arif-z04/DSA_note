#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* link;
    Node(int value){
        data = value;
        link = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    
    void push_front(int value){
        Node* newNode = new Node(value);
        newNode->link = head;
        head = newNode;
    }
};

int main()
{
    
}
