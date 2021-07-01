//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/

#include <bits/stdc++.h>
using namespace std;

bool isValidChar(char c) {
    return c != ' ' && !ispunct(c);
}

bool isPalindrome(string s) {
    
    int i=0;
    int j=s.length()-1;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    while(i<j){
        if(!isValidChar(s[i])) {
            i++;
            continue;
        }
        if(!isValidChar(s[j])) {
            j--;
            continue;
        }
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
    
}

int main()
{
    cout<<isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
