#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    string str; int i=1;

    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");
    in>>str;

    do{
        if(str.compare("Hajj") == 0)
            out<<"Case "<<i++<<": Hajj-e-Akbar\n";
        else if(str.compare("Umrah") == 0)
            out<<"Case "<<i++<<": Hajj-e-Asghar\n";
        
        in>>str;
    }while(str!="*");
    
    out.close(); in.close();

}