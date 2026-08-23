// Problem: Check ASCII Palindromic
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/check-ascii-palindromic/
// Solved on: 2026-08-23T13:50:56.392Z

class Solution {
public:
    bool isPalindromic(string s) {
        string binarystr = "";
        for(char c: s){
            int asciival = c;
            for(int i = 7; i >= 0; i--){
                int bit = (asciival >> i) & 1;
                binarystr += to_string(bit);
            }
        }
        int left = 0;
        int right = binarystr.length()-1;
        while(left<right){
            if(binarystr[left] != binarystr[right]) return false;
            left++;
            right--;
        }
        return true;
        
    }
};