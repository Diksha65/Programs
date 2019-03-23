#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int main(){

    string str, str1;
    set<string> st;
    map<string, vector<string> > maps;
    set<string>::iterator iter;
    ifstream in; in.open("input.txt");
    ofstream out; out.open("output.txt");
    while(in>>str && str != "#"){
        str1 = str;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        sort(str.begin(), str.end());
        maps[str].push_back(str1);
    }
    for(const auto p : maps){
        if (p.second.size() == 1)    
            st.insert(p.second[0]);
    }
    for(iter=st.begin(); iter != st.end();++iter){
        out<<*iter<<"\n";
    }

}