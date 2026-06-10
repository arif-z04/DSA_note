#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertFront(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void insertBack(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node<T> *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void deleteValue(T value)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->data == value)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T> *current = head;
        while (current->next != nullptr & current->next->data != value)
        {
            current = current->next;

            if (current->next != nullptr)
            {
                Node<T> *temp = current->next;
                current->next = temp->next;
                delete temp;
            }
        }
    }

    void search(T value)
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                cout << "Found! Data:" << value << endl;
                return;
            }
        }

        cout << "Not found" << endl;
    }

    // Display
    void display()
    {
        Node<T> *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

void displayWithAddress()
{
    Node<T> *temp = head;

    while (temp != NULL)
    {

        cout << "[" << temp->data << " | " << (long long)temp % 10000 << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

    // Destructor
    ~LinkedList()
    {
        Node<T> *current = head;

        while (current != nullptr)
        {
            Node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    list.displayWithAddress();
}