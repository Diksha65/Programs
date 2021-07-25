#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

/*
s1 = AFXDG
s2 = FVDELG
LCS between s1 and s2 = FDG = size 3.

s1 = STRIVER
s2 = RJUVR
LCS between s1 and s2 = RVR = size 3.

s1 = BCD
s2 = AEF
LCS between s1 and s2 = null = size 0.
*/

//3 ways
//1. Recursive
//2. DP - Bottom Up
//3. DP - Top Down

//Base Condition - Smallest valid input data set which is s1="", s2=""

//Time Complexity: O(2^n) exponential
int LCSRecursive(int n, int m, string s1, string s2) {
   
    if(n==0 || m==0) return 0;

    if(s1[n-1] == s2[m-1]) {
        return 1 + LCSRecursive(n-1, m-1, s1, s2);
    } else {
        return max(LCSRecursive(n-1, m, s1, s2), LCSRecursive(n, m-1, s1, s2));
    }
}

//Time Complexity: O(nm) where n = s1.size() and m = s2.size() -- TopBottom
int LCSMemoizationTB(int n, int m, string s1, string s2, vector<vector<int>> &dp) {
    if(n == 0 || m == 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n-1] == s2[m-1]) {
        return dp[n][m] = 1 + LCSMemoizationTB(n-1, m-1, s1, s2, dp);
    } else {
        return dp[n][m] = max(LCSMemoizationTB(n-1, m, s1, s2, dp), LCSMemoizationTB(n, m-1, s1, s2, dp));
    }
}

//Time Complexity: O(nm) where n = s1.size() and m = s2.size() -- BottomTop
int LCSMemoizationBT(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
   
    if(i>=s1.size() || j >= s2.size()) return 0;
   
    if(dp[i][j] != -1) {
        //Value was already calculated before
        return dp[i][j];
    }
   
    if(s1[i] == s2[j]) {
        return 1+LCSMemoizationBT(i+1, j+1, s1, s2, dp);
    } else {
        int left = LCSMemoizationBT(i+1, j, s1, s2, dp);
        int right = LCSMemoizationBT(i, j+1, s1, s2, dp);
        return dp[i][j] = max(left, right);
    }
}

//Time Complexity: O(nm) where n = s1.size() and m = s2.size()
int LCSDPTopDown(string s1, string s2, int n, int m) {
    
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
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int main()
{
   string s1 = "STRIVER";
   string s2 = "RJUVR";
   int n = s1.size();
   int m = s2.size();
   
   int lcsRecursive = LCSRecursive(0, 0, s1, s2);
   cout<<"LCS between "<<s1<<" and "<<s2<<" is of size (Using Recursion) : "<<lcsRecursive<<"\n";
   
   int lcsMemoizedTB = LCSMemoizationTB(s1.size(), 0=s2.size(), s1, s2);
   cout<<"LCS between "<<s1<<" and "<<s2<<" is of size (Using Memoization - TopBottom) : "<<lcsMemoizedTB<<"\n";

   int lcsMemoizedBT = LCSMemoizationBT(0, 0, s1, s2);
   cout<<"LCS between "<<s1<<" and "<<s2<<" is of size (Using Memoization - BottomTop) : "<<lcsMemoizedBT<<"\n";

   int lcsDPTopBottom = LCSDPTopDown(s1, s2, s1.size(), s2.size());
   cout<<"LCS between "<<s1<<" and "<<s2<<" is of size (Using DP Top Bottom) : "<<lcsDPTopBottom<<"\n";
   
   return 0;
}