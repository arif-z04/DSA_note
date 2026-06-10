#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    // Move element up (heapify up)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Move element down (heapify down)
    void heapifyDown(int index) {
        int n = heap.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Insert element
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Get max element
    int top() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Remove max element
    void pop() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty() {
        return heap.empty();
    }

    void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(40);

    cout << "Heap elements: ";
    pq.display();

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "After pop: ";
    pq.display();

    cout << "New top: " << pq.top() << endl;

    return 0;
}