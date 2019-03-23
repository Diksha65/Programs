#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    int t, n;
    map<string, int> mp;
    string word;
    cin>>t;
    while(t--){
        int cnt = 0;
        mp.clear();
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>word;
            if(mp.count(word) == 0)
                mp[word] = 1;
            else 
                mp[word] += 1;
        }
        for(pair<string, int> pa : mp){
            if(pa.second == 2){
                cout<<pa.first<<"\n";
                cnt += 1;
            }
        }
        cout<<cnt<<"\n";
    }
}