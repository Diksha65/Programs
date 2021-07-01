//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/

#include <bits/stdc++.h>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    // if(nums.size() == 1) {
    //     return nums[0];
    // }
    
    // sort(nums.begin(), nums.end()); //nlogn
    // int prevNum = -1;
    
    // for(int i=0;i<nums.size();i++) {
    //     if(nums[i] != prevNum && i == nums.size() - 1) {
    //         return nums[i];
    //     } else if(nums[i] != prevNum && nums[i] != nums[i+1]) {
    //         return nums[i];
    //     } else {
    //         prevNum = nums[i];
    //     }
    // }
    // return -1;
    
    int num = 0;
    for (int x: nums) {
        num ^= x;
    }
    return num;
}

int main()
{
    vector<int> a({2,4,1,2,1});
    cout<<singleNumber(a);

    return 0;
}