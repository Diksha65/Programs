#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){
    int c=0;
    for(int i=2;i<n;i=i+1)
        if(n%i==0)  
            c += 1;
    return (c==0);
}

bool isFactor(int i, int n){
    return n % i ==0;
}

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=n/2;i>0;i--){
            if(isPrime(i) && isFactor(i,n)){
                cout<<i<<"\n";
                break;
            }
        }
    }
}