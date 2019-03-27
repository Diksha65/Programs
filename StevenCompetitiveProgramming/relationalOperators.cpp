#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int no;
    long int a, b;
    ofstream outputFile;
    ifstream inputFile;
    outputFile.open("output.txt");
    inputFile.open("input.txt");
    inputFile>>no;
    for(int i=0; i<no;++i){
        inputFile>>a>>b;
        if(a == b)
            outputFile<<"=\n";
        else if(a<b)
            outputFile<<"<\n";
        else
            outputFile<<">\n";
    }
    outputFile.close();
    inputFile.close();
}