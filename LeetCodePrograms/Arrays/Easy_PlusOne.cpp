//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& d) {
    /*reverse(d.begin(), d.end());
    int carry = 1;
    for(int i=0;i<d.size();i++) {
        d[i] += carry;
        if(d[i] == 10) {
            carry = 1;
            d[i] = 0;
        } else {
            carry = 0;
        }
    }
    if(carry == 1) {
        d.push_back(1);
    }
    reverse(d.begin(), d.end());
    return d;*/
    
    //OORRRR
    
    int s = d.size();
    int carry = 1;
    for(int i=s-1;i>=0;i--) {
        d[i] = d[i]+carry;
        if(d[i] == 10) {
            carry = 1;
            d[i] = 0;
        } else {
            carry = 0;
        }
    }
    if(carry == 1) {
        d.insert(d.begin(), 1);
    }
    return d;
}

int main() {
    int n;
    cout<<"Enter a number to which 1 is to be added\n";
    cin>>n;
    vector<int> digits;
    while(n>0) {
        digits.push_back(n%10);
        n = n/10;
    }
    reverse(digits.begin(), digits.end());
    cout<<"The incremented number is:\n";
    digits = plusOne(digits);
    for(int x: digits){
        cout<<x;
    }
}