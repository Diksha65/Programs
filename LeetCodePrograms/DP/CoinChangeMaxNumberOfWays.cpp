/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, 
there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int coinChangeProblem(vector<int> coins, int amount) {
    int n = coins.size();
    vector<vector<int>> t(n+1, vector<int>(amount+1, 0));
    
    for(int i=0;i<n+1;i++) 
        t[i][0] = 1;
        
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<amount+1;j++) {
            if(coins[i-1] <= j) {
                t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][amount];
}

int main()
{
    vector<int> coins{1,2,3};
    int amount = 4;
    cout<<coinChangeProblem(coins, amount);
    return 0;
}
