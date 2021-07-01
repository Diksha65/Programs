//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

#include <bits/stdc++.h>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    // for(int i=0; i<k ;i++) {
    //     for(int j=nums.size()-1; j>0; j--) {
    //         swap(nums[j], nums[j-1]);
    //     }
    // }
    
    //ORRRRR
    
    int n = nums.size();
    k=k%n;   //if k > n then we just need to rotate the remainder number of times.
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
    
}

int main()
{
    vector<int> a({2,4,3,5,1});
    rotate(a, 3);

    for(int x: a) {
        cout<<x<<" ";
    }

    return 0;
}