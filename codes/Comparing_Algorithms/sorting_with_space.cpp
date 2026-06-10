#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// ---------------- Utility ----------------
vector<int> generateArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

// ---------------- Sorting Algorithms ----------------
void insertionSort(vector<int> arr) { int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int> arr) { int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex]) minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(vector<int> arr) { int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// ---------------- Merge Sort ----------------
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r)
        temp.push_back(arr[i] <= arr[j] ? arr[i++] : arr[j++]);

    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[l + k] = temp[k];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// ---------------- Quick Sort ----------------
int partition(vector<int>& arr, int l, int h) {
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

void quickSort(vector<int>& arr, int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

// ---------------- Timing Helper ----------------
template <typename F>
long long measure(F func, vector<int> arr) {
    auto start = high_resolution_clock::now();
    func(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

long long measureMerge(vector<int> arr) {
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

long long measureQuick(vector<int> arr) {
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

// ---------------- SPACE ESTIMATION ----------------
void printSpace(int n) {
    cout << "\nSpace Complexity (Estimated for n = " << n << "):\n\n";

    cout << "Insertion Sort : O(1) → ~0 bytes extra\n";
    cout << "Selection Sort : O(1) → ~0 bytes extra\n";
    cout << "Bubble Sort    : O(1) → ~0 bytes extra\n";

    cout << "Merge Sort     : O(n) → ~" << n * sizeof(int)
         << " bytes (~" << (n * sizeof(int)) / 1024.0 << " KB)\n";

    cout << "Quick Sort     : O(log n) stack → ~"
         << (int)(log2(n) * sizeof(int))
         << " bytes (~small stack usage)\n";
}

// ---------------- MAIN ----------------
int main() {
    const int SIZE = 1000;
    vector<int> original = generateArray(SIZE);

    cout << "Sorting Performance Comparison (n = 1000)\n\n";

    cout << "Insertion Sort : " << measure(insertionSort, original) << " µs\n";
    cout << "Selection Sort : " << measure(selectionSort, original) << " µs\n";
    cout << "Bubble Sort    : " << measure(bubbleSort, original) << " µs\n";
    cout << "Merge Sort     : " << measureMerge(original) << " µs\n";
    cout << "Quick Sort     : " << measureQuick(original) << " µs\n";

    printSpace(SIZE);

    return 0;
}