// Problem: Smallest Missing Multiple of K
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/smallest-missing-multiple-of-k/
// Solved on: 2026-08-25T02:59:34.769Z

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int>st(nums.begin(), nums.end());

        int x = k;
        while(st.count(x)){
            x+=k;

        }
        return x;
    }
};