#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubblesort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


int binarySearch(int arr[], int n, int item){
    int LB = 0;
    int UB = n - 1;
    

    // o(logn)
    while(LB <= UB){
        int mid = (LB + UB) / 2;
        if(arr[mid] == item){
            return mid;
        } else if (arr[mid] < item){
            LB = mid + 1;
        } else {
            UB = mid - 1;
        }
    }

    return -1;
}
int main(){
    int arr[] = {12, 2, 39, -4, 25};
    int n = sizeof(arr)/sizeof(int);
    int item = 39;

    cout << "Unsorted: " << endl;
    for(int i:arr) cout << i << " ";
    cout << endl;

    bubblesort(arr, n);
    
    cout << "Sorted: " << endl;
    for(int i:arr) cout << i << " ";
    cout << endl;


    cout << "Item: " << item << endl;
    cout << "Index: ";
    cout << binarySearch(arr, sizeof(arr)/sizeof(int), item) << endl;
    return 0;


}