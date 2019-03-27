#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int no, x_div, y_div;
    int x, y;
    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");
    in>>no>>x_div>>y_div;
    do{
        for(int i=1;i<=no;++i){
            in>>x>>y;
            if(x>x_div && y>y_div) out<<"NE\n";
            else if(x>x_div && y<y_div) out<<"SE\n";
            else if(x<x_div && y<y_div) out<<"SO\n";
            else if(x<x_div && y>y_div) out<<"NO\n";
            else if(x == x_div || y == y_div) out<<"divisa\n";
        }
        in>>no>>x_div>>y_div;
    } while(no>0);
    out.close(); in.close();
}