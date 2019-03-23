#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main(){
    int first_channel, last_channel;
    int forward_diff, backward_diff;

    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");

    in>>first_channel>>last_channel;
    do{
        forward_diff = 100; backward_diff = 100;
        forward_diff = abs(last_channel - first_channel);
        backward_diff = 100 - forward_diff;
        
        /* 
                    WROTE MY OWN. BUT ABOVE WAS BETTER.
        if(first_channel > last_channel && first_channel != 0 && first_channel > 50) 
            backward_diff = 100%first_channel + last_channel;
        if(last_channel > first_channel && last_channel != 0 && last_channel > 50)
            backward_diff = 100%last_channel + first_channel;
        */
        
        if(forward_diff < backward_diff)
            out<<forward_diff<<"\n";
        else
            out<<backward_diff<<"\n";
        in>>first_channel>>last_channel;
    }while(first_channel != -1 && last_channel != -1);

    out.close(); in.close();
}