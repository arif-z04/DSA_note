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

int main()
{
    Stack<int> s(5);
    s.push(5);
    s.push(7);
    s.push(8);
    s.display();
    s.pop();
    s.display();
    cout << s.isEmpty() << endl;
    cout << s.peek() << endl;

    return 0;

}