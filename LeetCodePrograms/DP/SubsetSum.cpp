#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool subsetSum(vector<int> vec, int sum) {
    int n = vec.size();
    vector<vector<bool>> t(n+1, vector<bool>(sum+1));
    
    for(int j=0;j<sum+1;j++)
        t[0][j] = false;
        
    for(int i=0;i<n+1;i++)
        t[i][0] = true;
        
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<sum+1;j++) {
            if(vec[i-1] <= j) {
                t[i][j] = t[i-1][j-vec[i-1]] || t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];    
            }
        }
    }
    
    return t[n][sum];
}

//Output - True/False
int main()
{
    vector<int> vec{2,3,7,9,10};
    int sum = 11;
    
    cout<<"Subset sum: "<<subsetSum(vec, sum)<<"\n";

    return 0;
}
