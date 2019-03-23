#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

#define lli long long int

int maxStocks(vector<pair<lli, lli> > vec, lli k){
    lli count = 0, x = 0, sum = 0;
    for(vector<pair<lli, lli> >::iterator it = vec.begin(); it!=vec.end(); ++it){
        if(sum <= k){
            x = ((k-sum)/it->first) < (it->second) ? (k-sum)/it->first : it->second;
            count += x;
            sum += it->first * x;
        } else {
            break;
        }
    }
    return count;
}

int main(){
    lli n, no;
    lli k;
    vector<pair<lli, lli> > vec;
    cin>>n;
    for(lli i=0; i<n;++i){
        cin>>no;
        vec.push_back(pair<lli, lli>(no, i+1));
    }
    sort(vec.begin(), vec.end(), [=](pair<lli, lli> &a, pair<lli, lli> &b){
        return a.first < b.first;
    });
    for(vector<pair<lli, lli> >::iterator it = vec.begin(); it!=vec.end(); ++it){
        cout<<it->first<<" "<<it->second<<"\n";
    }
    cin>>k;
    cout<<maxStocks(vec, k)<<"\n"; 
}