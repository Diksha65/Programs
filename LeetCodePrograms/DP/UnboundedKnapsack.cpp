#include <bits/stdc++.h>
#include <vector>
using namespace std;

int unboundedKnapsack(vector<int> wt, vector<int> val, int W) {
    int n = val.size();
    
    vector<vector<int>> t(n+1, vector<int>(W+1));
    
    //Initialization
    for(int j=0;j<W+1;j++) {
        tanh[0][j] = 0;
    }
    
    for(int i=0;i<n+1;i++){
        t[i][0] = 0;
    }

    for(int i=1;i<n+1;i++) {
        for(int j=1;j<W+1;j++) {
            if(wt[i-1] <= j) {
                t[i][j] = max((val[i-1]+t[i][j-wt[i-1]]), (t[i-1][j]));
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    vector<int> wt{1,3,5};
    vector<int> val{20, 30, 50};
    int W = 8;
    cout<<unboundedKnapsack(wt, val, W);

    return 0;
}