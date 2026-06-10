#include <bits/stdc++.h>
using namespace std;

int recursiveFactorial(int n){
    // base case
    if(n == 0) return 1;
    return n * recursiveFactorial(n - 1);
}

int main(){

    return 0;
}