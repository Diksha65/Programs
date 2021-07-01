//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/

#include <bits/stdc++.h>
#include<vector>
using namespace std;

//Both took same amount of time.
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //Without sorting
    unordered_map<int, int> m;
    vector<int> res;
    
    for(int x: nums1) {
        m[x]++;
    } 
    
    for(int x : nums2) {
        if(m[x] > 0) {
            res.push_back(x);
            m[x]--;
        }
    }
    return res;
    
    //With sorting
    //vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    int i=0, j=0;
    while(i<nums1.size() && j<nums2.size()) {
        if(nums1[i] == nums2[j]) {
            res.push_back(nums1[i]);
            i++; j++;
        } else if(nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums1 {4,9,5};
    vector<int> nums2 {9,4,9,8,4};
    
    for(int x: intersect(nums1, nums2)) {
        cout<<x<<" ";
    }

    return 0;
}