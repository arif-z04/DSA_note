#include <bits/stdc++.h>
using namespace std;

// Binary Search Algorithm

void sortedArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}


int main(){
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    int target = 5;

    sortedArray(arr);
    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}