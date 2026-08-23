// Problem: World Chess Championship
// Platform: codechef
// Contest: 935
// Rating/Difficulty: 935
// Language: C++17
// Verdict: Accepted
// URL: https://www.codechef.com/practice/course/strings-new/STRINGSP01/problems/WCC
// Solved on: 2026-08-23T07:25:12.192Z

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    while(T--){
        int x;
        string s;
        
        cin>>x>>s;
        
        int c = 0, n = 0;
        
        for(char ch : s){
            if(ch == 'C') c+=2;
            else if(ch == 'N') n+=2;
        }
        if(c>n){
            cout<<60*x<<endl;
        }
        else if(c<n){
            cout<<40*x<<endl;
        }
        else{
            cout<<55*x<<endl;
        }
    }
    return 0;
     

}
