#include <bits/stdc++.h>
#include <vector>
using namespace std;

//Time Complexity: O(2^N)
int maxProfitRecursion(vector<int> val, vector<int> wt, int W, int n) {
    if(n == 0 || W == 0) return 0;
    
    if(wt[n-1]<=W) {
        int includeThis = val[n-1] + maxProfitRecursion(val, wt, W-wt[n-1], n-1);
        int notIncludeThis = maxProfitRecursion(val, wt, W, n-1);
        return max(includeThis, notIncludeThis);
    } else {
        return maxProfitRecursion(val, wt, W, n-1);
    }
}

//Time Complexity: O(Wxn)
int maxProfitMemoization(vector<vector<int> > &dp, vector<int> val, vector<int> wt, int W, int n) {
    if(n == 0 || W == 0) return 0;
    
    if(dp[n][W] != -1) return dp[n][W];
    
    if(wt[n-1]<=W) {
        int includeThis = val[n-1] + maxProfitMemoization(dp, val, wt, W-wt[n-1], n-1);
        int notIncludeThis = maxProfitMemoization(dp, val, wt, W, n-1);
        return dp[n][W] = max(includeThis, notIncludeThis);
    } else {
        return dp[n][W] = maxProfitMemoization(dp, val, wt, W, n-1);
    }
}

//Time Complexity: O(Wxn)
int maxProfitTopDown(vector<int> val, vector<int> wt, int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1));
    
    //Initialization
    for(int j=0;j<W+1;j++) {
        dp[0][j] = 0;
    }
    
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }
    
    //Run iteratively
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<W+1;j++) {
            if(wt[i-1] <= j) {
                dp[i][j] = max((val[i-1] + dp[i-1][j-wt[i-1]]), (dp[i-1][j]));
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    vector<int> val{ 60, 100, 120 };
    vector<int> wt{ 10, 20, 30 };
    int W = 50;
    
    cout<<"Max Profit Using Recursion = "<<maxProfitRecursion(val, wt, W, val.size())<<"\n";

    vector<vector<int> > dp(val.size()+1, vector<int>(W+1, -1));
    cout<<"Max Profit Using Memoization = "<<maxProfitMemoization(dp, val, wt, W, val.size())<<"\n";
    
    cout<<"Max Profit Using Top Down Approach = "<<maxProfitTopDown(val, wt, W, val.size())<<"\n";
    return 0;
}
