/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
what is the minimum number of coins using which we can make the change?
For example, for N = 4 and S = {1,2,3}, 
there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 2 since the minimum number of coins needed is for {1,3}. 
For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 2 since the minimum nymber if coins needed is for {5,5}.
https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int coinChangeProblem(vector<int> coins, int amount) {
    int n = coins.size();
    vector<vector<int>> t(n+1, vector<int>(amount+1, 0));
    
    //Initialization
    for(int i=0;i<amount+1;i++)  //First row
        t[0][i] = INT_MAX-1;
    
    for(int i=0;i<n+1;i++) //First column
        t[i][0] = 0;
        
    for(int j=1;j<amount+1;j++) {   //Second row
        if(j%coins[0] == 0) 
            t[1][j] = j/coins[0];
        else 
            t[1][j] = INT_MAX - 1;
    }
    
    for(int i=2;i<n+1;i++) {
        for(int j=1;j<amount+1;j++) {
            if(coins[i-1] <= j) {
                t[i][j] = min((t[i][j-coins[i-1]] + 1), (t[i-1][j]));
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
    int amount = 3;
    cout<<coinChangeProblem(coins, amount);
    return 0;
}
