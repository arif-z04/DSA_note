#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int item){
    int LB = 0;
    int UB = n - 1;

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
    int item = 39;
    cout << binarySearch(arr, sizeof(arr)/sizeof(int), item) << endl;
    return 0;
}