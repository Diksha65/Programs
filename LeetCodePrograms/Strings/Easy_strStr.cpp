//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/

#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    
    int hs = haystack.size();
    int ns = needle.size();
    
    for(int i=0;i<=(hs-ns);i++) {
        int j; 
        for(j=0; j<ns; j++) {
            if(haystack[i+j] != needle[j]) {
                break;
            }
        }
        
        if(j==ns) {
            return i;
        }
    }
    
    return -1;
}

int main()
{
    cout<<strStr("hellllw", "llw");
    return 0;
}
