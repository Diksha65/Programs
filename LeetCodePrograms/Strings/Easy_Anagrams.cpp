//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/

#include <bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    
    unordered_map<char, int> m1, m2;
    for(int i=0;i<s.size();i++) {
        m1[s[i]]++;
        m2[t[i]]++;
    }
    
    if(m1==m2) 
        return true;
    else 
        return false;
}

int main()
{
    cout<<isAnagram("leetcode", "codeleet");
    return 0;
}