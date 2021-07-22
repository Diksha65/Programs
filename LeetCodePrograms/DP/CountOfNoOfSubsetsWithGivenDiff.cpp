// Online C++ compiler to run C++ program online
//Count the number of subsets with a given difference
//s1-s2 = difference
//s1+s2 = sum
//s1 = (difference + sum)/2

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int countOfSubsetSum(vector<int> vec, int sum) {
    int n = vec.size();
    
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));
    for(int i=0;i<n+1;i++) 
        t[i][0] = 1;
        
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


int countOfSubsetWithGivenDiff(vector<int> vec, int diff) {
    int sum=0;
    for(int i=0;i<vec.size();i++)
        sum+=vec[i];
        
    return countOfSubsetSum(vec, (sum+diff)/2);
}

int main()
{
    vector<int> vec{1,1,1,2,3};
    int diff = 1;
    cout<<countOfSubsetWithGivenDiff(vec, diff);

    return 0;
}
