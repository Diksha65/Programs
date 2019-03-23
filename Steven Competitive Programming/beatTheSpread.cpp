#include<iostream>
#include<fstream>
using namespace std;

void solve(long int &s, long int &d){
    long int sum = s, diff = d;
    s = (sum + diff) % 2 == 0 ? (sum + diff) / 2 : -1;
    d = sum - s;
}

int main(){
    
    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");
    int n;
    long int s, d;
    in>>n;
    while(n--){
        in>>s>>d;
        solve(s,d);
        if(s>=0 && d>=0)
            if(s>d)
                out<<s<<" "<<d<<"\n";
            else  
                out<<d<<" "<<s<<"\n";
        else
            out<<"impossible\n";   
    }

    out.close(); in.close();
}