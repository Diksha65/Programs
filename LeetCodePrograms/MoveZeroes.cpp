//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
        
    // for(int i=0;i<nums.size()-1;i++) {
    //     for(int j=0;j<nums.size()-1;j++) {
    //         if(nums[j] == 0 && nums[j+1] != 0) {
    //             swap(nums[j], nums[j+1]);
    //         }
    //     }
    // }
    
    int j=0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    for(int i=j;i<nums.size();i++) {
        nums[i]=0;
    }
}

int main() {
    int n,a;
    vector<int> digits;
    cout<<"Enter the total number of nos:\n";
    cin>>n;
    cout<<"Enter "<<n<<" numbers:\n";
    for(int i=0;i<n;i++) {
        cin>>a;
        digits.push_back(a);
    }
    cout<<"The changed array is:\n";
    moveZeroes(digits);
    for(int x: digits){
        cout<<x<<" ";
    }
}