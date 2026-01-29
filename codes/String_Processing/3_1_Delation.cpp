#include <bits/stdc++.h>
using namespace std;

int searchPattern(string str, string pattern){
    int pat_len = pattern.length();
    int str_len = str.length();

    for(int i = 0; i <= str_len - pat_len; i++){
        for(int j = 0; j < pat_len; j++){
            if(str[i + j] != pattern[j]){
                break;
            } else if (j == pat_len - 1){
                return i;
            }
        }
    }
    return -1; // not found
}


string erase(string str, int idx, int pattern_length){
    string temp = "";
    int length = str.length();

    for(int i = 0; i < length; i++){
        if(idx <= i && i <= idx + pattern_length - 1){
            continue;
        }
        temp += str[i];
    }

    return temp;
}

int main(){

    string str = "To be or not 2B, that is the B,?";
    string pattern = "B,";

    int index = searchPattern(str, pattern);

    while(index != -1){
        str = erase(str, index, pattern.length());
        index = searchPattern(str, pattern);
    }
    return 0;
}