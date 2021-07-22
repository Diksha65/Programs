/*
Given a array = {1,5,6,11}, find the minimum difference between the sum of 2 subsets from this array.
Ex: s1 = {1,5,6}, s2 = {11}
Difference = sum(s1) - sum(s2) = 12-11 = 1
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> subsetSum(vector<int> vec, int sum) {
    int n = vec.size();
    
    vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));
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
    
    vector<int> result;
    for(int i=0; i<(sum+1)/2;i++) {
        if(t[n][i]) result.push_back(i);
    }
    return result;
    
}

int minimumDifferenceInSubsetSum(vector<int> vec) {
    int totalSum=0;
    for(int i=0;i<vec.size();i++)
        totalSum+=vec[i];
        
    vector<int> possibleSumsForSubsetOne = subsetSum(vec, totalSum);
    
    int minimum = INT_MAX;
    int sum1, sum2;
    for(int i=0;i<possibleSumsForSubsetOne.size();i++) {
        sum1 = possibleSumsForSubsetOne[i];
        sum2 = totalSum - sum1;
        minimum = min(minimum, (sum2 - sum1));
    }
    return minimum;
}

int main()
{
   vector<int> vec{1, 5, 6, 11};
   cout<<minimumDifferenceInSubsetSum(vec);
   return 0;
}
