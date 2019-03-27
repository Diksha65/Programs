#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    string str;
    ofstream outputFile;
    ifstream inputFile;
    inputFile.open("input.txt");
    outputFile.open("output.txt");
    while(getline(inputFile, str))
        outputFile<<str<<"\n";
    outputFile.close();
    inputFile.close();
}