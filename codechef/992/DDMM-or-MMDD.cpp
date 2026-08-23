// Problem: DDMM or MMDD
// Platform: codechef
// Contest: 992
// Rating/Difficulty: 992
// Language: C++17
// Verdict: Accepted
// URL: https://www.codechef.com/practice/course/strings-new/STRINGSP01/problems/DDMMORMMDD
// Solved on: 2026-08-23T07:26:46.316Z

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int first = stoi(s.substr(0, 2));
        int second = stoi(s.substr(3, 2));

        bool ddmm = (first <= 31 && second <= 12);
        bool mmdd = (first <= 12 && second <= 31);

        if (ddmm && mmdd)
            cout << "BOTH\n";
        else if (ddmm)
            cout << "DD/MM/YYYY\n";
        else
            cout << "MM/DD/YYYY\n";
    }

    return 0;
}
