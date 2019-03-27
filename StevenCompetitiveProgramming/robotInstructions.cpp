#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int distances(vector<int> vec, int &pos){
    int sum = pos;
    for(int i=0;i<vec.size();++i)
        sum += vec[i];
    return sum;
}

int main(){
    int no_cases, no_instructions, p; string pos;
    vector<int> vec;

    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");

    in>>no_cases;
    for(int i=0;i<no_cases;++i){
        in>>no_instructions;
        int position = 0;
        for(int j=0 ; j < no_instructions ; j++){
            in>>pos;
            if(pos == "LEFT")
                vec.push_back(-1);
            else if(pos == "RIGHT")
                vec.push_back(1);
            else if(pos == "SAME"){
                in>>pos>>p;
                vec.push_back(vec[p-1]);
            }
        }
        int postn = distances(vec, position);
        out<<postn<<"\n";
        vec.clear();
    }

    out.close(); in.close();
}