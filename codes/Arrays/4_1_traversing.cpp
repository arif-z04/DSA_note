#include <bits/stdc++.h>
using namespace std;

/*

LA = Linear Array of n elements

set K = LB
while K <= UB
    apply PROCESS to LA[K]
    K++
EXIT
*/

void traverse_1(int arr[], int LB, int UB){
    int K = LB;
    while(K <= UB){
        cout << arr[K] << " ";
        K++;
    }
    cout << endl;
}


void traverse_2(int arr[], int LB, int UB){
    for(int i = LB; i <= UB; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
Repeat for K = LB to UB:
    Apply PROCESS to LA[K]
EXIT
*/

int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    traverse_1(arr, 0, 4);
    traverse_2(arr, 0, 4);
    return 0;
}