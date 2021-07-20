/*Question
Given a non-empty array nums containing only positive integers, 
find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 
Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/
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

bool equalSumPartition(vector<int> vec) {
    int sum=0;
    for(int i=0;i<vec.size();i++)
        sum+= vec[i];
    
    //Odd sum => cannot be divided to 2 subsets of equal sum
    if(sum%2!=0) return false;
    
    return subsetSum(vec, sum/2);
}

int main()
{
    vector<int> vec{2,3,7,8,10};
    
    cout<<"EqualSumPartition possible: "<<equalSumPartition(vec)<<"\n";

    return 0;
}


