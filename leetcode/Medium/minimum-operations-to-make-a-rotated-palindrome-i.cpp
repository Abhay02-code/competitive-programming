// Problem: Minimum Operations to Make a Rotated Palindrome I
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/
// Solved on: 2026-08-24T18:12:54.935Z

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;
        for(int r = 0; r < n; r++){
            string t = s.substr(r)+s.substr(0,r);
            int cost = 0;
            for(int i = 0, j = n-1; i < j; i++, j--){
                int diff = abs(t[i] -t[j]);
                cost  += min(diff, 26 - diff);
            }
            ans = min(ans, r+cost);
        }
        return ans;
    }
};