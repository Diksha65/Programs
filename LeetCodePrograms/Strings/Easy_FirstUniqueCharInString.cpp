//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/

#include <bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

int firstUniqChar(string s) {
        
    unordered_map<char, int> m;
    
    for(char c: s) {
        m[c]++;
    }
    
    for(int i=0;i<s.size();i++) {
        if(m[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout<<firstUniqChar("leetcode");
    return 0;
}