#include<iostream>
#include<vector>
using namespace std;

double calculate(vector<double> vec, int k, int start, int end){
    if((end == start + 1) && k > 0)
        return (vec[end]>vec[start]) ? vec[end]-vec[start] : 0;
    else if( k > 0 && end > (start+1) ){
        double sum = 0, sumNew = 0, m = 0, l;
        for(int i=start;i<=end;i+=1){
            for(int j=i+1;j<=end;j+=1){
                if(vec[j] >= vec[i]){
                    m = vec[j] - vec[i];
                    l = k-1;
                    sumNew = m + calculate(vec, l, j+1, end);
                    sum = max(sum, sumNew);
                }
            }
        }
        return sum;
    } else
        return 0;
}

int main(){
    int q, k, n;
    double price;
    vector<double> vec;
    cin>>q;
    while(q--){
        cin>>k>>n;
        for(int i=0;i<n;++i){
            cin>>price;
            vec.push_back(price);
        }
        cout<<calculate(vec, k, 0, vec.size()-1)<<"\n";
        vec.clear();
    }
}