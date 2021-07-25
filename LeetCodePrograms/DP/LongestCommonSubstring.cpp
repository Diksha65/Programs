#include <bits/stdc++.h>
#include <vector>
using namespace std;

int LCSubstring(string s1, string s2, int n, int m) {
    
    vector<vector<int>> dp(n+1, vector<int>(m+1));    
    
    for(int i=0;i<n+1;i++)
        dp[i][0] = 0;
        
    for(int j=0;j<m+1;j++)
        dp[0][j] = 0;
        
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<m+1;j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1 = "STRIVER";
    string s2 = "RJUVER";
    
    int n = s1.size();
    int m = s2.size();
    
    cout<<LCSubstring(s1, s2, n, m)<<"\n";
    
    return 0;
}