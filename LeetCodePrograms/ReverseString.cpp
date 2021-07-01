//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/

#include <bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

void reverseString(vector<string>& s) {
    int end = s.size()-1;
    int begin = 0;
    
    while(begin<end) {
        string temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        begin++;
        end--;
    }
    
}

int main()
{
    vector<string> a({"H","a","n","n","a","h"});
    reverseString(a);

    for(string x: a) {
        cout<<x<<" ";
    }

    return 0;
}