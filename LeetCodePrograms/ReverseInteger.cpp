//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/

#include <bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

int reverse(int x) {
    long int rev=0;
    int r;
    while(x!=0) {
        r=x%10;
        rev=rev*10+r;
        x=x/10;
    }
    if(rev<pow(-2, 31) || rev>pow(2,31)) {
        return 0;
    } else {
        return rev;
    }
        
}

int main()
{
    cout<<reverse(123456780);
    return 0;
}