#include <bits/stdc++.h>
#include <vector>
using namespace std;

int countOfSubsetSum(vector<int> vec, int n, int sum) {
    
    vector<vector<int>> t(n+1, vector<int>(sum+1,0));
    
    for(int i=0;i<n+1;i++) {
        t[i][0] = 1;
    }
    
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<sum+1;j++) {
            if(vec[i-1] <= j) {
                t[i][j] = t[i-1][j-vec[i-1]] + t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
    
}

int main()
{
    vector<int> vec{2,3,4,6,8,10};
    int sum = 10;
    cout<<countOfSubsetSum(vec, vec.size(), sum);
    return 0;
}
