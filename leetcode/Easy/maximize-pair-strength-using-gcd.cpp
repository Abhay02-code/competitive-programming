// Problem: Maximize Pair Strength Using GCD
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/maximize-pair-strength-using-gcd/
// Solved on: 2026-08-25T12:48:34.718Z

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] == 0 && nums[j] ==0) continue;
                long long g = gcd(nums[i], nums[j]);
                long long strength = (1LL * nums[i] * nums[j])/(g*g);
                ans = max(ans, strength);
            }
        }
        return ans;
        
    }
};