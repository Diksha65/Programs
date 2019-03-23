#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;

ofstream out; ifstream in;

void printBooklet(int pages){
    double n = (double) pages/4;
    int sheets = ceil(n);
    n = 4*sheets;
    int s=0;
    bool flag = true;
    vector<int> pg(n, 0);
    for(int i=0;i<pages;++i)
        pg[i] = i+1;
    for(int i=0;i<pg.size()/2;++i){
        int no = pg[pg.size()-1-i];
        if(no == 0 && pg[i] == 0)
            break;
        if(flag && s<=sheets){
            s += 1;
            out<<"Sheet "<<s<<", front: ";
            if(no == 0)
                out<<"Blank"<<", "<<pg[i]<<"\n";
            else
                out<<no<<", "<<pg[i]<<"\n";
            flag = false;
        } else {
            out<<"Sheet "<<s<<", back : "<<pg[i]<<", ";
            if(no == 0)
                out<<"Blank"<<"\n";
            else    
                out<<no<<"\n";
            flag = true;
        }
    }
}

int main(){
    int pages;
    out.open("output.txt"); in.open("input.txt");
    in>>pages;    
    while(pages>0){
        out<<"Printing order for "<<pages<<" pages:\n";
        printBooklet(pages);
        in>>pages;
    }

    out.close(); in.close();
}