// Problem: Lexicographically Smallest Permutation Greater Than Target
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
// Solved on: 2026-08-27T06:18:30.419Z

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        // Frequency of a-z
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int i = 0;

        // Step 1: Try to match target from left to right
        for (; i < n; i++) {

            int x = target[i] - 'a';

            if (freq[x] == 0) {
                break;
            }

            freq[x]--;
        }

        // ------------------------------------------------
        // Case 1: We could NOT match target at position i
        // ------------------------------------------------

        if (i < n) {

            // First try to make CURRENT position bigger
            int current = target[i] - 'a';

            for (int k = current + 1; k < 26; k++) {

                if (freq[k] > 0) {

                    string ans = target.substr(0, i);

                    // Put the smallest possible bigger character
                    ans += char('a' + k);

                    freq[k]--;

                    // Put remaining characters in sorted order
                    for (int c = 0; c < 26; c++) {

                        while (freq[c] > 0) {
                            ans += char('a' + c);
                            freq[c]--;
                        }
                    }

                    return ans;
                }
            }

            // Current position cannot be made bigger.
            // So go backwards and change an earlier position.

            for (int j = i - 1; j >= 0; j--) {

                // Restore target[j]
                freq[target[j] - 'a']++;

                int current = target[j] - 'a';

                // Find smallest character > target[j]
                for (int k = current + 1; k < 26; k++) {

                    if (freq[k] > 0) {

                        string ans = target.substr(0, j);

                        // Make this position bigger
                        ans += char('a' + k);

                        freq[k]--;

                        // Remaining characters in sorted order
                        for (int c = 0; c < 26; c++) {

                            while (freq[c] > 0) {
                                ans += char('a' + c);
                                freq[c]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // ------------------------------------------------
        // Case 2: Target was completely matched
        // We need STRICTLY greater than target
        // ------------------------------------------------

        for (int j = n - 1; j >= 0; j--) {

            // Restore target[j]
            freq[target[j] - 'a']++;

            int current = target[j] - 'a';

            // Find smallest character greater than target[j]
            for (int k = current + 1; k < 26; k++) {

                if (freq[k] > 0) {

                    string ans = target.substr(0, j);

                    ans += char('a' + k);

                    freq[k]--;

                    // Remaining characters in sorted order
                    for (int c = 0; c < 26; c++) {

                        while (freq[c] > 0) {
                            ans += char('a' + c);
                            freq[c]--;
                        }
                    }

                    return ans;
                }
            }
        }

        // No permutation greater than target
        return "";
    }
};