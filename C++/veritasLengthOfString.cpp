#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<char> a = {'d','i','k','s','h','a', 'a','g','a','r','w','a','l'};
    char *p = &a[0];
    int len=0;
    while(*p){
        len += 1;
        p++;
    }
    cout<<len<<"\n";
}
/*
int main(){
    string str="Diksha";
    int i=0, len=0;
    while(str[i] != '\0'){
        len += 1;
        i += 1;
    }
    cout<<len<<"\n";
}*/
