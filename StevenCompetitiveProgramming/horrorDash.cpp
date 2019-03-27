#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int no_cases;
    int participants, x;
    vector<int> vec;

    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");

    in>>no_cases;
    for(int i=0;i<no_cases; ++i){
        in>>participants;
        for(int j=0;j<participants; ++j){
            in>>x;
            vec.push_back(x);
        }
        int max = *max_element(vec.begin(), vec.end());
        out<<"Case "<<i+1<<": "<<max<<"\n";
        vec.clear();
    }

    out.close(); in.close();
}