#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int> &nums){
        if(nums.empty()) return 0;
        int idx = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[idx] = nums[i];
                idx++;
            }
            return idx; 
        }

    }


};
int main()
{
    
    return 0;
}