#include<iostream>
#include<vector>
#include<string>
using namespace std;

string reverse(string str){
    if(str.length() == 0)
        return "";
    return str[str.length() - 1] + reverse(str.substr(0, str.length()-1));
}

int main(){
    string str = "Diksha";
    cout<<reverse(str);
}