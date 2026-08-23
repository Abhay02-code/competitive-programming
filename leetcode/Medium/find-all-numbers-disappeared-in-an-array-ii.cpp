// Problem: Find All Numbers Disappeared in an Array II
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/
// Solved on: 2026-08-23T14:02:10.264Z

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int prev = lower-1;
        for(int x : nums){
            if(x<lower || x>upper) continue;
            if(x>prev+1) ans.push_back({prev+1,x-1});
            prev = x;
        }
        if(prev < upper){
            ans.push_back({prev+1, upper});
        }
        return ans;
        
    }
};