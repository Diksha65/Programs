/*
string s1 = "AGGTAB" //m = 6
string s2 = "GXTXAYB" //n = 7
Output:
Supersequence = merge both s1 and s2 with minimum length 
"AGGXTXAYB" // Length = 9
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int LCS(string s1, string s2, int m, int n) {
    
    vector<vector<int>> t(m+1, vector<int>(n+1));
    
    for(int i=0;i<m+1;i++)
        t[i][0] = 0;
    
    for(int j=0;j<n+1;j++)
        t[0][j] = 0;
        
    for(int i=1; i<m+1; i++) {
        for(int j=1;j<n+1;j++) {
            if(s1[i-1] == s2[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    
    return t[m][n];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    
    int m = s1.size();
    int n = s2.size();
    
    cout<<m+n-LCS(s1, s2, m, n);

    return 0;
}
