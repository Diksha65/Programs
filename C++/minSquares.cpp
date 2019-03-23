/*
#include<iostream>
#include<cmath>
using namespace std;

int minSquares(int l, int b){
    int h_min=999, v_min=999;
    if(l == b)
        return 1;
    for(int i=1;i<l/2;++i)
        h_min = min(minSquares(l-i, b) + minSquares(i, b), h_min);
    for(int i=1;i<b/2;++i)
        v_min = min(minSquares(l, b-i) + minSquares(l, i), v_min);
    
    return min(h_min, v_min);
}

int main(){
    int n, a, b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        cout<<minSquares(a,b);
    }
}*/

#include<bits/stdc++.h>
using namespace std;
 
const int MAX = 300;
int dp[MAX][MAX];
 
int minimumSquare(int m, int n)
{
    int vertical_min = INT_MAX;
    int horizontal_min = INT_MAX;
     
    if (m == n)
        return 1;
     
    if (dp[m][n])
            return dp[m][n];
     
    for (int i = 1;i<= m/2;i++)
        horizontal_min = min(minimumSquare(i, n) + 
                minimumSquare(m-i, n), horizontal_min); 
     
    for (int j = 1;j<= n/2;j++)
        vertical_min = min(minimumSquare(m, j) + 
                minimumSquare(m, n-j), vertical_min);

    dp[m][n] = min(vertical_min, horizontal_min); 
         
    return dp[m][n];
}
 
int main()
{
    int m = 30, n = 35;
    cout << minimumSquare(m, n);
    return 0;
}
 