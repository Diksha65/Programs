#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPalin(string s){
    int start = 0;
    int end = s.size()-1;
    if(end == start+1)
        return s[start] == s[end];
    if(end == start)
        return true;
    
    if(s[start] == s[end]){
        string str = s.substr(start+1, end-1);
        if(isPalin(str))
            return true;
        else 
            return false;
    }
}

void palindrome(string str, int length){
    int count = 0;
    for(int i=0;i<length;++i){
        for(int j=length-i;j>1;j--){
            string s = str.substr(i, j);
            if(isPalin(s)){
                count += 1;
            }
        }
    }
    cout<<count<<"\n";
}

int main(){
    int t, n;
    string str;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>str;
        palindrome(str, n);
    }
}
