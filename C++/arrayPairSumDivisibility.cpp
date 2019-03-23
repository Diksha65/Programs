#include<iostream>
#include<vector>
using namespace std;

void checkPair(vector<int> vec, int k){
    vector<bool> vb(vec.size(), false);
    for(int i=0; i<vec.size(); ++i){
        for(int j=i+1; j<vec.size(); ++j){
            if(!vb[i] && !vb[j]){
                if((vec[i] + vec[j]) % k == 0){
                    vb[i] = true;
                    vb[j] = true;
                }
            }
        }
    }
    for(int i=0;i<vb.size(); ++i){
        if(!vb[i]){
            cout<<"False\n";
            return;
        }
    }
    cout<<"True\n";
    return;
}

int main(){
    int t, n, k, no;
    vector<int> vec;
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            cin>>no;
            vec.push_back(no);
        }
        cin>>k;
        checkPair(vec, k);
        vec.clear();
    }
}