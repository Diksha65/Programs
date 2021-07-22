/*
Input vec = [1,1,2,3]
Sum = 1
In how many ways can we assign '+' or '-' sign before a number in the vector such that the sum of all the elements is 1.
Example:
Output for above = 3
+1, -1, +2, -3 = |(1+2) - (1+3)| = |3-4| = 1
-1, +1, -2, +3 = |(1+3) - (1+2)| = |4-3| = 1
+1, +1, +2, -3 = |(1+1+2) - (3)| = |4-3| = 1

This problem is exactly same as "Count the number of subset pairs whoes difference is the given difference"
*/
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
    
    //s1-s2 = diff
    //s1+s2 = sum
    //s1 = (sum+diff)/2
    return countOfSubsetSum(vec, (diff+sum)/2);
}

int main()
{
   vector<int> vec{1, 1, 2, 3};
   int diff = 1;
   cout<<countOfSubsetWithGivenDiff(vec, diff);
   return 0;
}