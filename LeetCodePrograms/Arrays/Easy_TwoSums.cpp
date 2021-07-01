//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/

#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        
        /*for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(target - nums[i] == nums[j]) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }*/
        
        //ORRR 
        
        /*for(int i=0;i<nums.size();i++) {
            m[nums[i]] = i;
        }
        
        for(int i=0;i<nums.size();i++) {
            if(m.find(target - nums[i]) != m.end() && m[target-nums[i]] != i) {
                     result.push_back(i);
                     result.push_back(m[target-nums[i]]);
                     return result;
                 }
        }*/
        
        //ORRRRR
        
        for(int i=0;i<nums.size();i++) {
            if(m.count(target-nums[i]) > 0) {
                return vector<int>({i, m[target-nums[i]]});
            }
            
            m.insert(make_pair(nums[i], i));
        }
        
        return vector<int>({0,0});
    }

int main()
{
    vector<int> a = vector<int>({-1, -2, -3, -4, -5});
    vector<int> result = twoSum(a, -7);
    for(int x: result) {
        cout<<x<<" ";
    }
    return 0;
}