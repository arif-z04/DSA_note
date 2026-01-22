#include <bits/stdc++.h>
using namespace std;

/*
LA = linear array
K = positive integer
such that K <= N

SET J = N
Repeat next steps while J >= K
    SET LA[J + 1] = LA[J]
    SET J = J - 1
SET LA[K] = ITEM
SET N = N + 1
Exit

*/

int insert(int arr[], int n, int k, int item){
    int j = n - 1;
    while(j >= k){
        arr[j + 1] = arr[j];
        j--;
    }

    arr[k] = item;
    return n + 1;
}


void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){
    int arr[50] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;
    int item = 10;

    n = insert(arr, n, k - 1, item);
    printArray(arr, n);

    return 0;
}