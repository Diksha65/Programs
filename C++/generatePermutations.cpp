#include<iostream>
#include<string>
#include< Set >
using namespace std;

Set<string> generatePermutations(string str){
    Set<string> result;
    if(str == "")
        result += "";
    for(int i=0;i<str.length();++i){
        char ch = str[i];
        string rest = str.substr(0,i)+str.substr(i+1);
        foreach(string s in generatePermutations(rest))
            result += ch+s;
    }
    return result;
}

int main(){
    string str;
    cout<<"enter a string";
    cin>>str;
    cout<<"\nThe permutations of "<<str<<" are: \n";
    foreach(string s in generatePermutations(str))
        cout<<s<<"\n";
}