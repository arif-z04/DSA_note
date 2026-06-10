#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// ---------------- Utility: Generate Random Array ----------------
vector<int> generateArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

// ---------------- Insertion Sort ----------------
void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------------- Selection Sort ----------------
void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// ---------------- Bubble Sort ----------------
void bubbleSort(vector<int> arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break; // optimization
    }
}

// ---------------- Merge Sort ----------------
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// ---------------- Quick Sort ----------------
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------- Timing Helper ----------------
template <typename Func>
long long measureTime(Func func, vector<int> arr) {
    auto start = high_resolution_clock::now();
    func(arr);
    auto end = high_resolution_clock::now();

    return duration_cast<microseconds>(end - start).count();
}

// Overload for recursive sorts (merge/quick)
long long measureTimeMerge(vector<int> arr) {
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();

    return duration_cast<microseconds>(end - start).count();
}

long long measureTimeQuick(vector<int> arr) {
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();

    return duration_cast<microseconds>(end - start).count();
}

// ---------------- Main ----------------
int main() {
    const int SIZE = 10000;
    vector<int> original = generateArray(SIZE);

    cout << "Sorting Performance Comparison (n = 1000)\n\n";

    cout << "Insertion Sort : " << measureTime(insertionSort, original) << " microseconds\n";
    cout << "Selection Sort : " << measureTime(selectionSort, original) << " microseconds\n";
    cout << "Bubble Sort    : " << measureTime(bubbleSort, original) << " microseconds\n";
    cout << "Merge Sort     : " << measureTimeMerge(original) << " microseconds\n";
    cout << "Quick Sort     : " << measureTimeQuick(original) << " microseconds\n";

    cout << "\nSpace Complexity:\n";
    cout << "Insertion Sort : O(1)\n";
    cout << "Selection Sort : O(1)\n";
    cout << "Bubble Sort    : O(1)\n";
    cout << "Merge Sort     : O(n) auxiliary space\n";
    cout << "Quick Sort     : O(log n) average (recursion stack)\n";

    return 0;
}