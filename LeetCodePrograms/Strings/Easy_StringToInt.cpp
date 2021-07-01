//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/

#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    if (s.length() == 0) return 0;
    
    bool isPos = true;
    long int res = 0;
    int index = 0;
    
    //Read in and ignore any leading whitespace.
    while(s[index] == ' ') index++; 
    
    //final result is negative or positive
    if(s[index] == '-' || s[index] == '+') {
        isPos = s[index]=='+';
        index++;
    } 
    
    //Read in next the characters until the next non-digit charcter or the end of the input is reached
    for(int i=index;i<s.size();i++) {
        if(s[i]>='0' && s[i]<='9') {
            
            if(res*10 + (s[i]-'0') > INT_MAX) {
                return isPos ? INT_MAX : INT_MIN;
            }
            
            res = res*10+(s[i]-'0');  
        } else {
            break;
        }
    }
    
    return isPos ? res : -res;
}

int main()
{
    cout<<myAtoi("-91283472332");
    return 0;
}
