#include <bits/stdc++.h>
using namespace std;

template<typename T>
class PriorityQueue {
private:
    vector<T> heap;

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
    void push(T value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    T top() {
        if (heap.empty())
            throw runtime_error("Priority Queue is empty!");

        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    void display() {
        for (T x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    cout << "Heap: ";
    pq.display();

    cout << "Top: " << pq.top() << endl;

    pq.pop();

    cout << "After Pop: ";
    pq.display();

    return 0;
}