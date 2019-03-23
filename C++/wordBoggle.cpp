#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


void print(vector<string> name){
    for(int i=0;i<name.size();++i)
        cout<<name[i]<<" ";
    cout<<"\n";
}

void print(vector<char> name){
    for(int i=0;i<name.size();++i)
        cout<<name[i]<<" ";
    cout<<"\n";
}


vector<char> split(string name){
    vector<char> vec;
    for(int i=0;i<name.length();++i)
        vec.push_back(name[i]);
    return vec;
}

bool in(char c, vector<char> ch){
    for(int i=0;i<ch.size(); ++i){
        if(c == ch[i])
            return true;
    }
    return false;
}

bool find(vector<char> c, vector<char> ch){
    int count = 0;
    for(int i=0;i<c.size();++i){
        if(in(c[i], ch))
            count++;
        else    
            return -1;
    }
    return count;
}

bool compareFunction(string a, string b){
    return a<b;
}

bool wordBoggle(vector<string> word, vector<char> ch){
    vector<string> finals;
    vector<char> c;
    for(int i=0;i<word.size();++i){
        c = split(word[i]);
        cout<<"\nc"<<c.size();
        cout<<"\nf"<<find(c,ch);
        if(find(c, ch) == c.size()){
            cout<<word[i]<<"\n";
            finals.push_back(word[i]);
            print(finals);
        }
    }
    if(finals.empty())
        return false;
    else{
        sort(finals.begin(), finals.end(), compareFunction);
        print(finals);
        return true;
    }
}

int main(){
    int t, dicts, n, m;
    string wd;
    char ch;
    vector<string> word;
    vector<char> vec;
    cin>>t;
    while(t--){
        cin>>dicts;
        while(dicts--){
            cin>>wd;
            word.push_back(wd);
        }
        cin>>n>>m;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                cin>>ch;
                vec.push_back(ch);
            }
        if(!wordBoggle(word, vec))
            cout<<"-1\n";
        
        word.clear();
        vec.clear();
    }
}