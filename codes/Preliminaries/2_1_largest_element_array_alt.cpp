#include <bits/stdc++.h>
using namespace std;

void LargestElementArray(int data[], int n){
    int mx = data[0];
    int loc = 0;
    for(int i = 0; i < n; i++){
        if(data[i] > mx){
            mx = data[i];
            loc = i;
        }
    }
    cout << "LOC = " << loc << ", MAX = " << mx << endl;
}

int main(){
    int arr[] = {3, 5, 9, 8};
    int n = sizeof(arr)/sizeof(int);
    LargestElementArray(arr, n);

    return 0;
}