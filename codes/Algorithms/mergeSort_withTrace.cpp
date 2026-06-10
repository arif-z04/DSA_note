#include <bits/stdc++.h>
using namespace std;

// Merge function with trace
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    cout << "\nMerging: ";
    for (int i = 0; i < n1; i++) cout << L[i] << " ";
    cout << "and ";
    for (int j = 0; j < n2; j++) cout << R[j] << " ";
    cout << endl;

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    cout << "Result: ";
    for (int x = left; x <= right; x++)
        cout << arr[x] << " ";
    cout << "\n";
}

// Merge Sort function with trace
void mergeSort(int arr[], int left, int right, int depth = 0) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // show division
        cout << string(depth * 2, ' ');
        cout << "Dividing: ";
        for (int i = left; i <= right; i++)
            cout << arr[i] << " ";
        cout << endl;

        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);

        merge(arr, left, mid, right);
    }
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";

    mergeSort(arr, 0, n - 1);

    cout << "\nFinal Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}