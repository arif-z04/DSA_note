#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at front
    void insertFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertBack(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = newNode;
            return;
        }

        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert after Nth node (1-based index)
    void insertAfterPosition(int pos, T value) {
        Node<T>* temp = head;

        for (int i = 1; i < pos && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (!temp) return;

        Node<T>* newNode = new Node<T>(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete front
    void deleteFront() {
        if (!head) return;

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete end
    void deleteEnd() {
        if (!head) return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at position (1-based)
    void deleteAtPosition(int pos) {
        if (!head) return;

        if (pos == 1) {
            deleteFront();
            return;
        }

        Node<T>* temp = head;

        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) return;

        Node<T>* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void display() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList<int> list;

    // -------------------------
    // Scenario 1: 20, 30 exist
    list.insertBack(20);
    list.insertBack(30);

    // insert 10 at start
    list.insertFront(10);

    // insert 50 at end
    list.insertBack(50);

    // insert 40 after 3rd node
    list.insertAfterPosition(3, 40);

    cout << "After insert operations:\n";
    list.display();

    // -------------------------
    // Scenario 2: 10 20 30 exist
    LinkedList<int> list2;
    list2.insertBack(10);
    list2.insertBack(20);
    list2.insertBack(30);

    list2.deleteFront();

    cout << "After deleting front:\n";
    list2.display();

    // -------------------------
    // Scenario 3: 20 30 40 exist
    LinkedList<int> list3;
    list3.insertBack(20);
    list3.insertBack(30);
    list3.insertBack(40);

    list3.deleteEnd();

    cout << "After deleting end:\n";
    list3.display();

    // -------------------------
    // Scenario 4: 20 30 50 60 exist
    LinkedList<int> list4;
    list4.insertBack(20);
    list4.insertBack(30);
    list4.insertBack(50);
    list4.insertBack(60);

    list4.deleteAtPosition(3);

    cout << "After deleting 3rd node:\n";
    list4.display();

    return 0;
}