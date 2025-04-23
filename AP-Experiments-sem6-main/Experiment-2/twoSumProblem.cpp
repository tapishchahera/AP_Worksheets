/* 
Given an array of integers nums and an integer target, 
return the indices of the two numbers such that they add up to target. 
Each input has exactly one solution, and you cannot use the same element twice.
*/

// Time complexity: O(n)
// Space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    vector<int> res;
    for(int i=0; i<nums.size(); i++){
        if(mp.find(target-nums[i]) != mp.end()){
            res.push_back(mp[target-nums[i]]);
            res.push_back(i);
            return res;
        }
        mp[nums[i]] = i;
    }
    return res;
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}

