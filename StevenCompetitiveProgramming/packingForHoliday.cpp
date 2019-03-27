#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int no, L, B, H;

    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");

    in>>no;
    for(int i=0;i<no;++i){
        in>>L>>B>>H;
        if(L<=20 && B<=20 && H<=20)
            out<<"Case "<<i+1<<": good\n";
        else
            out<<"Case "<<i+1<<": bad\n";
    }
    out.close();
    in.close();
}