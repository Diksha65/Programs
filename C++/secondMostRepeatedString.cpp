#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    int t, n;
    string word;
    map<string, int> mp;
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            cin>>word;
            if(mp.count(word) == 0)
                mp[word] = 1;
            else   
                mp[word] += 1;
        }
        int first = 0, second = 0;
        string name = " ";
        for(pair<string, int> pa : mp){
            if(pa.second > first){
                second = first;
                word = name;
                first = pa.second;
                name = pa.first;
            } else if(pa.second > second && pa.second != first){
                second = pa.second;
                word = pa.first;
            }
        }
        cout<<word<<"\n";
        mp.clear();
    }
}