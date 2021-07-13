#include <bits/stdc++.h>
#include <vector>
using namespace std;

int minimumCostPathRecursive(int i, int j, vector<vector<int>> vec) {
    int n = vec.size();
    int m = vec[0].size();
    
    if(i>=n || j >=m) return INT_MAX;
    
    if(i==n-1 && j == m-1) return vec[i][j];
    
    int right = minimumCostPathRecursive(i, j+1, vec);
    int bottom = minimumCostPathRecursive(i+1, j, vec);
    return vec[i][j]+min(right, bottom);
}

int minimumCostPathDPBottomTop(int i, int j, vector<vector<int>> &vec, vector<vector<int>> &dp) {
    int n = vec.size();
    int m = vec[0].size();
    
    if(i>=n || j>=m) return INT_MAX;
    
    if(i == n-1 && j == m-1) return vec[i][j];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int right = minimumCostPathDPBottomTop(i, j+1, vec, dp);
    int bottom = minimumCostPathDPBottomTop(i+1, j, vec, dp);
    int min = right<bottom ? right : bottom;
    return dp[i][j] = vec[i][j] + min;
}

int minimumCostPathDPTopBottom(int i, int j, vector<vector<int>> vec, vector<vector<int>> &dp) {
    int n = vec.size();
    int m = vec[0].size();
    
    if(i<0 || j<0) return INT_MAX;
    
    if(i==0 && j==0) return vec[i][j];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int left = vec[i][j] + minimumCostPathDPTopBottom(i, j-1, vec, dp);
    int top = vec[i][j] + minimumCostPathDPTopBottom(i-1, j, vec, dp);
    int min = left<top ? left : top;
    return dp[i][j] = min;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> vec(n, vector<int>(m,0));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    vector<vector<int>> dp1(n, vector<int>(m, -1));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>vec[i][j];
        }
    }

    cout<<"Minimumum Cost Path using recusrion: "<<minimumCostPathRecursive(0,0,vec)<<"\n";
    cout<<"Minimumum Cost Path using DP(Bottom-Top): "<<minimumCostPathDPBottomTop(0,0,vec,dp)<<"\n";
    cout<<"Minimumum Cost Path using DP(Top-Bottom): "<<minimumCostPathDPTopBottom(n-1,m-1,vec,dp1)<<"\n";
    return 0;
}
