//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/

#include <bits/stdc++.h>
#include<vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    // unordered_map<int, int> m;
    // for(int x: nums) {
    //     if(m.count(x) > 0) {
    //         return true;
    //     }
    //     m[x]++;
    // }
    // return false;
    
    //ORRRRR
    //Took almost half time as compared to the above solution
    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size()-1;i++) {
        if(nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> a({2,4,3,5,1});
    cout<<containsDuplicate(a);

    return 0;
}