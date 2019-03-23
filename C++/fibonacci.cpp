#include<iostream>
using namespace std;

int additiveSequence(int n, int t0, int t1){
    if(n==0) return t0;
    if(n==1) return t1;
    else{
        cout<<"additiveSequence("<<n-1<<","<<t1<<","<<t1+t0<<")\n";
        return additiveSequence(n-1,t1,t0+t1);
    }
}

int fib(int n){
    cout<<"additiveSequence("<<n<<",0,1)\n";
    return additiveSequence(n, 0, 1);
}

int main(){
    int n = fib(5);
    cout<<n<<"\n";
}