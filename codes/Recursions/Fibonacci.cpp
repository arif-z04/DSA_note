#include <bits/stdc++.h>
using namespace std; 

int fibonacciSeries(int n){
    if(n == 0 || n == 1) return n;
    return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
}


int main(){
    
}