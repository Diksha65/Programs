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

//Time Complexity: O(2^n)
int LCSRecursive(int i, int j, string s1, string s2) {
   
    if(i>=s1.size() || j >= s2.size()) return 0;
   
    if(s1[i] == s2[j]) {
        return 1+LCSRecursive(i+1, j+1, s1, s2);
    } else {
        int left = LCSRecursive(i+1, j, s1, s2);
        int right = LCSRecursive(i, j+1, s1, s2);
        return max(left, right);
    }
}

//Time Complexity: O(nm) where n = s1.size() and m = s2.size()
int LCSDPBottomTop(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
   
    if(i>=s1.size() || j >= s2.size()) return 0;
   
    if(dp[i][j] != -1) {
        //Value was already calculated before
        return dp[i][j];
    }
   
    if(s1[i] == s2[j]) {
        return 1+LCSDPBottomTop(i+1, j+1, s1, s2, dp);
    } else {
        int left = LCSDPBottomTop(i+1, j, s1, s2, dp);
        int right = LCSDPBottomTop(i, j+1, s1, s2, dp);
        return dp[i][j] = max(left, right);
    }
}

//Time Complexity: O(nm) where n = s1.size() and m = s2.size()
int LCSDPTopBottom(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
   
    if(i<0 || j<0) return 0;
   
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
   
    if(s1[i] == s2[j]) {
        return 1+LCSDPTopBottom(i-1, j-1, s1, s2, dp);
    } else {
        int left = LCSDPTopBottom(i-1, j, s1, s2, dp);
        int right = LCSDPTopBottom(i, j-1, s1, s2, dp);
        return dp[i][j] = max(left, right);
    }
}

int main()
{
   string s1 = "STRIVER";
   string s2 = "RJUVR";
   int n = s1.size();
   int m = s2.size();
   
   int lcsRecursive = LCSRecursive(0, 0, s1, s2);
   cout<<"LCS between "<<s1<<" and "<<s2<<" is of size (Using Recursion) : "<<lcsRecursive<<"\n";
   
   vector<vector<int>> dp(n, vector<int>(m, -1));
   //Starting from i=0 and j=0;
   int lcsDPBottomTop = LCSDPBottomTop(0,0,s1, s2, dp);
   cout<<"LCS between "<<s1<<" and "<<s2<<" is of size (Using DP Bottom-Top) : "<<lcsDPBottomTop<<"\n";
   
   vector<vector<int>> dp1(n, vector<int>(m, -1));
   //Starting from i=n-1 and j=m-1;
   int lcsDPTopBottom = LCSDPTopBottom(n-1,m-1,s1, s2, dp1);
   cout<<"LCS between "<<s1<<" and "<<s2<<" is of size (Using DP Top-Bottom) : "<<lcsDPTopBottom<<"\n";
   
   return 0;
}