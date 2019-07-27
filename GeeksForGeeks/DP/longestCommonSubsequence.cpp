#include<bits/stdc++.h>
using namespace std;

void longestCommonSubsequence(string s1, string s2) {
    vector<vector<int>> lcs(s1.size()+1, vector<int>(s2.size()+1));
    for(int i=0;i<=s1.size();i++) {
        for(int j=0;j<=s2.size();j++) {
            if(i==0||j==0) 
                lcs[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) 
                lcs[i][j] = 1+lcs[i-1][j-1];
            else 
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    cout<<"Length of max subsequence: "<<lcs[s1.size()][s2.size()]<<"\n";
    int row = s1.size();
    int col = s2.size();
    int val = lcs[row][col];
    string result = "";
    while(val > 0) {
        if(val != lcs[row-1][col] && val != lcs[row][col-1]) {
            result = s1[row-1]+result;
            row = row-1;
            col = col - 1;
            val = lcs[row][col];
        } else if(val == lcs[row][col-1]) {
            col = col-1;
        } else if(val == lcs[row-1][col]) {
            row = row-1;
        }
    }
    cout<<result<<"\n";
}

int main() {
    string s1 = "abcdaf";
    string s2 = "acbcf";
    longestCommonSubsequence(s1, s2);
}