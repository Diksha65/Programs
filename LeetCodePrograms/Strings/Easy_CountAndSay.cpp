//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string countAndSay(int n) {
        
    if (n==1) return "1";
    
    string ans = countAndSay(n-1);
    string res = "";
    int count = 1;
    char ele = ans[0];
    for(int i=1;i<ans.size();i++) {
        
        if(ans[i] != ele) {
            res += to_string(count);
            res.push_back(ele);
            ele = ans[i];
            count = 1;
        } else {
            count++;
        }
    }
    res += to_string(count);
    res.push_back(ele);
    cout<<"Result for "<<n<<" is "<<res<<"\n";
    return res;
} 

int main()
{
    cout<<countAndSay(4);
    return 0;
}
