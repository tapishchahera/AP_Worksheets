/* 
You are given a 0-indexed array nums of length n. You are initially positioned at nums[0]. 
Each element nums[i] represents the maximum length of a forward jump from index i. 
Return the minimum number of jumps to reach nums[n - 1].
*/

// Time complexity: O(n)
// Space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0, currentEnd = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }
    return jumps;
}

int main(){
    vector<int> nums = {2,3,0,1,4};
    cout<<jump(nums);
    return 0;
}