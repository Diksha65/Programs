#include<iostream>
#include<fstream>
using namespace std;

int main(){
    
    int no_cases = 75, no_events;
    int x, to_give_treat, treat_given;
    
    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");
    
    for(int i=1;i<=no_cases;++i){
        in>>no_events;
        if(no_events <= 0) break;
        to_give_treat = 0; treat_given = 0;
        for(int j=0;j<no_events; ++j){
            in>>x;
            if(x == 0) treat_given += 1;
            else if(x > 0) to_give_treat += 1;
        }
        out<<"Case "<<i<<": "<<to_give_treat - treat_given<<"\n";
    }
    out.close(); in.close();
}