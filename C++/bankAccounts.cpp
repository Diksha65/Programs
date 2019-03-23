#include<iostream>
#include<vector>
using namespace std;

void calculate(vector<double> vec, double k, double x, double d){

    double sum = 0, temp;
    for(int i=0;i<vec.size();++i){
        temp = x*vec[i]/100;
        sum += max(k, temp);
    }
    if(sum <= d)
        cout<<"fee\n";
    else 
        cout<<"upfront\n";
}

int main(){
    double k, x, d, no;
    int n, q;
    vector<double> vec;
    cin>>q;
    while(q--){
        cin>>n>>k>>x>>d;
        for(int i=0;i<n;++i){
            cin>>no;
            vec.push_back(no);
        }
        calculate(vec, k, x, d);
        vec.clear();
    }
}