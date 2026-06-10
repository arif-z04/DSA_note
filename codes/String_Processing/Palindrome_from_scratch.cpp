#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
private:
    T *arr;
    int top;
    long capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    ~Stack(){
        delete[] arr;
    }

    void push(T value){
        if(top == capacity - 1){
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    T pop(){
        if(isEmpty()){
            cout << "Stack Underflow!" << endl;
            return T();
        }

        return arr[top--];
    }


    bool isEmpty(){
        return (top == -1);
    }

    bool isFull(){
        return (top == capacity - 1);
    }

    T peek(){
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
            return T();
        }

        return arr[top];
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
        }

        cout << "Stack: ";

        for(int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};


template<typename T>
class Queue{    
private:
    T* arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size){
        capacity = size;
        arr = new T[capacity];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1 || front > rear;
    }

    bool isFull(){
        return rear == capacity - 1;
    }

    void enqueue(T value){
        if(isFull()){
            cout << "OVERFLOW!" << endl;
            return;
        }
        if(front == -1){
            front = 0;
        }
        arr[++rear] = value;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "UNDERFLOW" << endl;
            return;
        }
        front++;
        if(front > rear){
            front = rear = -1;
        }
    }

    T getFront(){
        if(isEmpty()){
            cout << "EMPTY QUEUE" << endl;
            return T();
        }
        return arr[front];
    }

    T getRear(){
        if(isEmpty()){
            cout << "EMPTY QUEUE" << endl;
            return T();
        }
        return arr[rear];
    }

    void display(){
        if(isEmpty()){
            cout << "EMPTY QUEUE" << endl;
        }
        cout << "Queue: ";
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


bool isPalindrome(string s) {
    Stack<char> st(s.length());
    Queue<char> q(s.length());

    // handle empty string or single character
    if (s.length() <= 1) return true;

    // push into stack and queue
    for (char c : s) {
        st.push(c);
        q.enqueue(c);
    }

    // compare both
    while (!st.isEmpty() && !q.isEmpty()) {
        char fromStack = st.pop();
        char fromQueue = q.getFront();
        q.dequeue();

        if (fromStack != fromQueue) {
            return false;
        }
    }

    return true;
}

int main() {
    string s;
    getline(cin, s);

    if (isPalindrome(s)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}