#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isSteppingNumber(int n){
    if(n%10 == n)
        return true;
    
    int num = n, d1, d2;
    while(n != 0 && n%10 != n){
        d1 = n%10;
        d2 = (n%100) / 10;
        n = n/10;
        if(abs(d2-d1) != 1)
            return false;
    }
    return true;
}

int main(){
    int t, n, m, count=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=n;i<=m;++i){
            if(isSteppingNumber(i))
                count+=1;
        }
        cout<<count<<"\n";
        count = 0;
    }
}