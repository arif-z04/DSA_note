#include <bits/stdc++.h>
using namespace std;

// Partition using LOW pivot (first element)
int partitionLow(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] > pivot) j--;

        if (i > j) break;
        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}
// Partition using HIGH pivot (last element)
int partitionHigh(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSortLow(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionLow(arr, low, high);
        quickSortLow(arr, low, p - 1);
        quickSortLow(arr, p + 1, high);
    }
}

void quickSortHigh(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionHigh(arr, low, high);
        quickSortHigh(arr, low, p - 1);
        quickSortHigh(arr, p + 1, high);
    }
}