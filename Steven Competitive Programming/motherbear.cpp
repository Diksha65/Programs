#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

bool checkCharacter(char c){
    if(isalpha(c))
        return false;
    return true;
}

string formatString(string str){
    str.erase(remove_if(str.begin(), str.end(), checkCharacter), str.end());
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool isPalindrome(string str){
    int n = str.length();
    int j = n-1;
    for(int i=0;i<n;++i)
        if(str[i] != str[j--])
            return false;
    return true;
}

int main(){
    string str;
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    while(getline(in, str) && str != "DONE"){
        str = formatString(str);
        if(isPalindrome(str))
            out<<"You won't be eaten!\n";
        else
            out<<"Uh oh..\n";
    }
    out.close(); in.close();
}