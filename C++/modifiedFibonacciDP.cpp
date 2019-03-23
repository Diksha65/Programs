#include<iostream>
#include<vector>
using namespace std;

int fibonacci(vector<long long int> &vec, int n){
    if(vec[n] == -99){
        if(n<=1)
            vec[n] = n;
        else   
            vec[n] = fibonacci(vec, n-2) + (fibonacci(vec, n-1) * fibonacci(vec, n-1));
    }
    return vec[n];
}


int main(){
    int t1, t2, n;
    cin>>t1>>t2>>n;
    vector<long long int> vec(n,-99);
    cout<<fibonacci(vec, n-1)<<"\n";
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<" ";
}