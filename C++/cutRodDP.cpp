#include<iostream>
#include<vector>
#include<limits>
using namespace std;

const int inf = numeric_limits<int>::max();

int cutRod(vector<int> p, int n){
    if(n==0)
        return 0;
    int q = -9999;
    for(int i=1; i<=n;++i)
        q = max(q, p[i-1] + cutRod(p, n-i));
    return q;
}

int memoizedCutRodAux(vector<int> p, int n, vector<int> r){
    if(r[n] >= 0)
        return r[n];
    int q;
    if(n==0)
        q = 0;
    else {
        q = -inf;
        for(int i=1;i<=n;++i)
            q = max(q, p[i-1] + memoizedCutRodAux(p, n-i, r));
    }
    r[n] = q;
    return q;    
}

int memoizedCutRod(vector<int> p, int n){
    vector<int> rev(n+1, -inf);
    return memoizedCutRodAux(p, n, rev);
}

int main(){
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    vector<int> prices(p, p + sizeof(p)/sizeof(p[0]));
    int n;
    cin>>n;
    //cout<<cutRod(prices, n)<<"\n";
    cout<<memoizedCutRod(prices,n)<<"\n";
}