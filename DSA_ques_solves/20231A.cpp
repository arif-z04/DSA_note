#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val){
        data = val;
        next = NULL;
    }
};



template <typename T>
class SortedLinkedList
{
private:
    Node<T> *head;
    int capacity;
    int size;

public:
    SortedLinkedList(int cap)
    {
        head = NULL;
        capacity = cap;
        size = 0;

    }

    void insert(T val)
    {

        if(size >= capacity){
            cout << "List is full! Cannot insert" << val << endl;
            return;
        }   

        Node<T> *newNode = new Node<T>(val);

        // insert at beginning

        if(head == NULL || head->data >= val){
            newNode->next = head;
            head = newNode;
            size++;
            return;
        }

        Node<T>* temp = head;
        while(temp->next != NULL && temp->next->data < val){
            temp = temp->next;
        }


        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }


    void remove(T val){
        if(head == NULL){
            return;
        }

        if(head->data == val){
            Node<T>* del = head;
            head = head->next;
            delete del;
            size--;
            return;
        }

        Node<T>* temp = head;
        while(temp->next != NULL & temp->next->data != val){
            temp = temp->next;
        }

        if(temp->next == NULL) return;

        Node<T>* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        size--;
    }


    void display(){
        Node<T>* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int getSize() {return size;}
    int getCapacity() {return capacity;}


};
int main() {
    SortedLinkedList<string> list(10); 

    list.insert("BBBB");
    list.insert("DDDD");
    list.insert("MMMM");
    list.insert("XXXX");

    cout << "Initial list: ";
    list.display();

    list.insert("FFFF");
    list.insert("ZZZZ"); 
    cout << "After insertions: ";
    list.display();

    list.remove("MMMM");

    cout << "After deleting MMMM: ";
    list.display();

    cout << "Size: " << list.getSize()
         << " / Capacity: " << list.getCapacity() << endl;

    return 0;
}