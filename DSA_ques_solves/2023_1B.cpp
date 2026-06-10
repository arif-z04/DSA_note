/*

suppose, you are given  two input strings: A text string, T and a pattern string P. Write a program to implement
Naive Pattern Matching Algorithm. The Program should search for all occurances of the pattern in the text and 
print the starting indices of each match

*/

#include <bits/stdc++.h>

using namespace std;

void naivePatternMatching(string T, string P){
    int n = T.length();
    int m = P.length();

    bool found = false;

    for(int i = 0; i <= n - m; i++){
        int j;

        for(j = 0; j < m; j++){
            if(T[i + j] != P[j]){
                break;
            }
        }

        if(j == m){
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }

    if(!found){
        cout << "Pattern Not Found" << endl;
    }

}


int main() {
    string T, P;
    cout << "Enter text string: ";
    getline(cin, T);

    cout << "Enter pattern string: ";
    getline(cin, P);

    naivePatternMatching(T, P);
    return 0;
}