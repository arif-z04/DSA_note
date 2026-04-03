#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* link;

    int id;
    static int counter;

    Node(int value){
        data = value;
        link = NULL;

        id = ++counter;
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

    void pop_back(){
        if(head == NULL) return;

        if(head->link == NULL){
            delete head;
            head = NULL;
            return;
        }


        Node* temp = head;
        while(temp->link->link != NULL){
            temp = temp->link;
        }

        delete temp->link;
        temp->link = NULL;
    }

    void deleteFromPosition(int pos){
        if(head == NULL) return;

        if(pos == 1){
            pop_front();
        }

        Node* temp = head;

        for(int i = 1; i < pos - 1 && temp->link != NULL; i++){
            temp = temp->link;
        }
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


    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next;

        while(curr != NULL){
            next = curr->link;
            curr->link = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};




int main(){

}