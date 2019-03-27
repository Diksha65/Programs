#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    int no, amount, total=0;
    string action;

    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");

    in>>no;
    for(int i=0;i<no;++i){
        in>>action;
        if(action.compare("donate") == 0){
            in>>amount;
            total += amount;
        } else if(action.compare("report") == 0){
            out<<total<<"\n";
        }
    }

    out.close(); in.close();
}