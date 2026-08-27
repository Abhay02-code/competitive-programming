// Problem: Repeated DNA Sequences
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/repeated-dna-sequences/
// Solved on: 2026-08-27T07:13:06.817Z

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string>ans;
        unordered_map<string,int>freq;
        if(n < 10) return ans;
        for(int i = 0; i <= n-10; i++){
            string sub = s.substr(i, 10);
            freq[sub]++;

            if(freq[sub] == 2){
                ans.push_back(sub);
            }
        }
        return ans;

        
    }
};