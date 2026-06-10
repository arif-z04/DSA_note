#include <bits/stdc++.h>

using namespace std;

template<typename T>
class CircularQueue{
private:
    T* arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n){
        size = n;
        arr = new T[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (front == (rear + 1) % size);
    }

    void enqueue(T value){
        if(isFull()){
            cout << "OVERFLOW" << endl;
        }

        if(isEmpty()){
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "UNDERFLOW!" << endl;
            return;
        }

        if(front == rear){
            front = rear = -1;
        }

        else{
            front = (front + 1) % size;
        }
    }

    void display(){
        if(isEmpty()){
            cout << "EMPTY QUEUE" << endl;
            return;
        }

        cout << "Queue: ";

        int i = front;

        while(true){
            cout << arr[i] << " ";

            if(i == rear){
                break;
            }

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main(){

    CircularQueue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // queue becomes full

    q.display();

    cout << "q.dequeue()" << endl;
    q.dequeue();
    q.display();

    cout << "q.dequeue()" << endl;
    q.dequeue();
    q.display();


    cout << "Adding 60, 70:" << endl;
    q.enqueue(60);
    q.enqueue(70);

    q.display();


    return 0;
}