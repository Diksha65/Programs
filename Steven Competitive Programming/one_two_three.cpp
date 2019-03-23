#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool compare(string str, string str1, int n){
    int f=0;
    for(int i=0;i<n;++i)
        if(str[i] != str1[i])
            f = f + 1;
    if(f <= 1)
        return true;
    else
        return false;
}

int main(){
    int no;
    string str;

    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");

    in>>no;
    for(int i=0;i<no;++i){
        in>>str;
        if(str.length() == 3){
            if(compare(str,"one", 3)) 
                out<<"1\n";
            else 
                out<<"2\n";   
        }
        else 
            out<<"3\n";
    }

    out.close(); in.close();
}