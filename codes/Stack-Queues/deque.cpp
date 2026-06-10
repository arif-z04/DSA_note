#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T value) {
        data = value;
        next = prev = nullptr;
    }
};

template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* rear;
    int sz;

public:
    Deque() {
        front = rear = nullptr;
        sz = 0;
    }

    void insertFront(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        sz++;
    }

    void insertRear(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        sz++;
    }

    void deleteFront() {
        if (!front) return;

        Node<T>* temp = front;
        front = front->next;

        if (front)
            front->prev = nullptr;
        else
            rear = nullptr;

        delete temp;
        sz--;
    }

    void deleteRear() {
        if (!rear) return;

        Node<T>* temp = rear;
        rear = rear->prev;

        if (rear)
            rear->next = nullptr;
        else
            front = nullptr;

        delete temp;
        sz--;
    }

    void display() {
        Node<T>* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        return sz;
    }

    void displayWithAddress() {
        Node<T>* temp = front;
        while (temp) {
            cout << "[" << temp->data << " | " << temp << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


int main(){
    Deque<int> dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    cout << "Deque after insertions: ";
    dq.display();

    dq.deleteFront();
    cout << "Deque after deleting front: ";
    dq.display();

    dq.deleteRear();
    cout << "Deque after deleting rear: ";
    dq.display();

    return 0;
}

