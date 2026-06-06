#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};

int main()
{

    vector<int> nums = {1, 2, 3, 4};
    vector<int> rnSum;

    for(int i = 0; i < nums.size(); i++){
        int sum = 0;
        for(int j = 0; j <= i; j++){
            sum += nums[j];
            cout << nums[j] << "+";
        }
        cout << endl;
        rnSum.push_back(sum);
    }

    return 0;
}