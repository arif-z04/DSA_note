// first in first out

#include <bits/stdc++.h>

using namespace std;

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
int main()
{
    int n;

    cout << "Queue size? :";
    cin >> n;
    Queue<int> q(n);

    cout << "Enter the numbers: ";
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        q.enqueue(x);
    }

    q.display();

    q.dequeue();

    q.display();

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    
    return 0;
}