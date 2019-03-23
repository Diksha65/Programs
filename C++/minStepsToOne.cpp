#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int minimum(int a, int b, int c){
    int min = a;
    if(b<a && b<c)
        min = b;
    else if(c<a && c<b)
        min = c;
    return min;
}

int dprog(int n){
    vector<int> dp(n+1, -1);
    dp[1] = 0;
    for(int i=2;i<=n;++i){
        dp[i] = 1 + dp[i-1];
        if(i%2 == 0) dp[i] = min(dp[i], 1+dp[i/2]);
        if(i%3 == 0) dp[i] = min(dp[i], 1+dp[i/3]);
    }
    return dp[n];
}

int main(){
    int n = 10;
    cout<<dprog(n)<<"\n";
}