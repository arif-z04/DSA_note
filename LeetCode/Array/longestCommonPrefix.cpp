#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // string longestCommonPrefix(vector<string>& strs) {
    //     if(strs.empty()) return "";

    //     for(int i = 0; i < strs[0].length(); i++){
    //         char c = strs[0][i];

    //         for(int j = 1; j < strs.size(); j++){
    //             if(i == strs[j].length() || strs[j][i] != c){
    //                 return strs[0].substr(0, i);
    //             }
    //         }
    //     }


    //     return strs[0];
    // }


    string longestCommonPrefix(vector<string>& strs){
        if(strs.empty()) return "";

        // alphabetically sorting
        sort(strs.begin(), strs.end());

        string first = strs.front();
        string last = strs.back();
        string result = "";

        for(int i = 0; i < min(first.length(), last.length()); i++){
            if(first[i] != last[i]){
                break;
            }
            result += first[i];
        }

        return result;
    }
};

