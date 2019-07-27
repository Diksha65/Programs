#include<bits/stdc++.h>
using namespace std;

void knapsack(vector<int> wt, vector<int> val, int W, int n) {
    vector<vector<int>> KS(n+1, vector<int> (W+1));
    
    for(int i=0;i<n+1;i++) {
        for(int j=0;j<W+1;j++) {
            if(i==0 || j==0) 
                KS[i][j] = 0;
            else if(wt[i-1] > j) 
                KS[i][j] = KS[i-1][j];
            else 
                KS[i][j] = max((val[i-1] + KS[i-1][j-wt[i-1]]), KS[i-1][j]);
        }
    }
    
    cout<<"Maximum value for Weight "<<W<<" is "<<KS[n][W]<<"\n";
    //Finding the elements of knapsack
    int row = n, col = W, value = KS[n][W];
    while(value > 0) {
        if(value == KS[row-1][col]) {
            //upar se aaya hai.
            row = row-1;
        } else {
            cout<<"Weight = "<<wt[row-1]<<" Value = "<<val[row-1]<<"\n";
            col = col-wt[row-1];
            row = row-1;
            value = KS[row][col];
        }
    }
}

int main() {
    vector<int> wt = {1,3,4,5};
    vector<int> val = {1,4,5,7};
    int W = 7;
    int n = wt.size();
    knapsack(wt, val, W, n);
}