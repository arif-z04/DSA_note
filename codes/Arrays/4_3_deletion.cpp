#include <bits/stdc++.h>
using namespace std;
/*
Set ITEM = LA[K]
Repeat for j = k to n - 1
    Set LA[j] = LA[J + 1]
SET N = N - 1

*/
int deleteElement(int arr[], int n, int k){
    for(int j = k; j < n - 1; j++){
        arr[j] = arr[j + 1];
    }
    return n - 1;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[50] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;

    n = deleteElement(arr, n, k - 1);
    printArray(arr, n);
}