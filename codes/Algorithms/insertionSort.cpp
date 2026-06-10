#include <bits/stdc++.h>
using namespace std;


// O(n^2)
void insertionSort(int *arr, int size){
    for(int i = 1; i < size; i++){
        int x = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > x){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = x;
    }
}

void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[] = {5, 2, 4, 6, 1, 3};
    int size = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, size);
    printArr(arr, size);
    return 0;
}