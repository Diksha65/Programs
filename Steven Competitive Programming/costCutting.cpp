#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int no;
    vector<int> vec(3);
    ofstream out;
    out.open("output.txt");
    ifstream in;
    in.open("input.txt");
    in>>no;
    for(int i=0;i<no;i++){
        in>>vec[0]>>vec[1]>>vec[2];
        sort(vec.begin(), vec.end());
        out<<"Case "<<i+1<<": "<<vec[1]<<"\n";
    }
    out.close();
    in.close();
}