#include <bits/stdc++.h>
using namespace std;

int searchPattern(string str, string pattern){
    int pat_len = pattern.length();
    int str_len = str.length();

    for(int i = 0; i <= str_len - pat_len; i++){
        for(int j = 0; j < pat_len; j++){
            if(str[i + j] != pattern[j]){
                
            }
        }
    }
}

int main(){


    return 0;
}