#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<set>
using namespace std;

set<string> searchFor(string str, vector<pair<string, string> > vec){
    set<string> v;
    for(int i=0;i<vec.size(); ++i)
        if(vec[i].second == str)
            v.insert(vec[i].first);
    return v;
}

void display(set<string> f, vector<pair<string, string> > vec){
    vector<string> found(f.size());
    copy(f.begin(), f.end(), back_inserter(found));
    for(int j=0;j<found.size();++j){
        for(int i=0;i<vec.size();++i){
            if(vec[i].first == found[j])
                cout<<vec[i].second<<"\n";
        }
    }

}

int main(){
    vector<pair<string,string> > vec;
    string first, name, str;
    ifstream in; in.open("input.txt");
    while(getline(in, first, '$') && getline(in, name, '$') && !first.empty())
        vec.push_back(make_pair(first, name));
    
    cout<<"Enter the search string: ";
    cin>>str;
    set<string> found = searchFor(str, vec);
    display(found, vec);
}