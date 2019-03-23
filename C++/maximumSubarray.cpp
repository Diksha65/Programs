#include<iostream>
#include<vector>
#include<limits>
using namespace std;

const int inf = numeric_limits<int>::max();
void contiguous(vector<int> vec){
    int maxEndingHere  = 0, maxSoFar = 0, maxi = 0, min = -inf;
    for(int i=0;i<vec.size();++i){
        maxEndingHere = max(vec[i], maxEndingHere + vec[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
        if(vec[i] >= 0)
            maxi += vec[i];
        else if(vec[i] < 0 && vec[i] > min)
            min = vec[i];
    }
    maxi = (maxi == 0) ? min : maxi;
    maxSoFar = (maxSoFar == 0) ? min : maxSoFar;
    cout<<maxSoFar<<" "<<maxi<<"\n";
}

int main(){
    int T, N, a;
    vector<int> vec;
    cin>>T;
    while(T--){
        cin>>N;
        while(N--){
            cin>>a;
            vec.push_back(a);
        }
        contiguous(vec);
        vec.clear();
    }
}