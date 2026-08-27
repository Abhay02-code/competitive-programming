// Problem: Longest Harmonious Subsequence
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/longest-harmonious-subsequence/
// Solved on: 2026-08-27T07:02:31.819Z

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(int x : nums){
            freq[x]++;
        }
        int ans = 0;
        for(auto it : freq){
            int x = it.first;
            if(freq.find(x+1) != freq.end()){
                int length = freq[x]+freq[x+1];

                ans = max(ans, length);
            }
        }
        return ans;
        
    }
};