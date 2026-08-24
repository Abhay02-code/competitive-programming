// Problem: Elevator Requests I
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/elevator-requests-i/
// Solved on: 2026-08-24T17:58:14.929Z

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int sum = 0;
        int current = 0;
        for(int i = 0; i < requests.size(); i++){
            sum += abs((current- requests[i]));
            current = requests[i];
        }
        return sum;
        
    }
};