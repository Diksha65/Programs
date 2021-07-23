/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, if the length of the rod is 8 and the values of different pieces are given as the following, 
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1) 
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int rodCutting(vector<int> length, vector<int> price, int L) {
    int n = length.size();
    vector<vector<int>> t(n+1, vector<int>(L+1));
    
    for(int i=0;i<n+1;i++) 
        t[i][0] = 0;
        
    for(int j=0;j<L+1;j++)
        t[0][j] = 0;
        
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<L+1;j++) {
            if(length[i-1] <= j) {
                t[i][j] = max((price[i-1] + t[i][j-length[i-1]]), (t[i-1][j]));
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][L];
}

int main()
{
    vector<int> length;
    vector<int> price{3,5,8,9,10,17,17,20};
    int L = 8;
    for(int i=1;i<L;i++) {
        length.push_back(i);
    }
    cout<<rodCutting(length, price, L);
    return 0;
}