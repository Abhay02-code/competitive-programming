// Problem: K-th Digit in Infinite String
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/k-th-digit-in-infinite-string/
// Solved on: 2026-08-24T18:36:22.966Z

class Solution {
public:
    int kthDigit(long long k) {
        
        // First block: 1 2 3 4 5 6 7 8 9
        if (k <= 9)
            return k;

        k -= 9;

        // d = number of digits in each number
        long long d = 2;

        while (true) {
            long long first = 1;

            for (int i = 0; i < d - 2; i++)
                first *= 10;

            long long blocks = 9 * first;
            long long blockDigits = 10 * d;
            long long totalDigits = blocks * blockDigits;

            if (k > totalDigits) {
                k -= totalDigits;
                d++;
            }
            else {
                break;
            }
        }

        // Make k zero-indexed
        k--;

        long long first = 1;

        for (int i = 0; i < d - 2; i++)
            first *= 10;

        // Find block
        long long blockIndex = k / (10 * d);
        long long b = first + blockIndex;

        // Position inside block
        long long pos = k % (10 * d);

        // Find number
        long long numberIndex = pos / d;

        long long number;

        if (b % 2 == 0)
            number = 10 * b + numberIndex;
        else
            number = 10 * b + (9 - numberIndex);

        // Find digit inside number
        long long digitIndex = pos % d;

        string s = to_string(number);

        return s[digitIndex] - '0';
    }
};