#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isEven(int n){
        return !(n & 1);
    }

    int countDigit(int n){
        return log10(abs(n)) + 1;
    }

    int findNumbers(vector<int> &nums){
        vector<int>counts;
        int cnt = 0;
        for(int n:nums) counts.push_back(countDigit(n));
        for(int n:counts) if(isEven(n)) cnt++;
        return cnt;
    }   
};

int main(){


}