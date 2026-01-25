#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    // adjacency_matrix
    int mat[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; i < n; j++){
            cin >> mat[i][j];   
        }
    }
    return 0;
}