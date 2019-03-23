#include<iostream>
#include<vector>
using namespace std;

int twoElementGroup(vector<int> vec){
    int cnt = 0;
    for(int i=0;i<vec.size(); ++i){
        for(int j=i+1;j<vec.size();++j){
            if((vec[i] + vec[j]) % 3 == 0)
                cnt += 1;
        }
    }
    return cnt;
}

int threeElementGroup(vector<int> vec){
    int cnt = 0;
    for(int i=0;i<vec.size(); ++i){
        for(int j=i+1;j<vec.size();++j){
            for(int k=j+1; k<vec.size(); ++k){
                if((vec[i] + vec[j] + vec[k]) % 3 == 0)
                    cnt += 1;
            }
        }
    }
    return cnt;
}

int main(){
    int n, t, no, cnt=0;
    vector<int> vec;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>no;
            vec.push_back(no);
        }
        cnt += twoElementGroup(vec);
        cnt += threeElementGroup(vec);
        cout<<cnt<<"\n";
        cnt = 0;
        vec.clear();
    }
}