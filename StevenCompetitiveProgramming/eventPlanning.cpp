#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int maximize(vector<int> vec){
    int max = vec[0];
    for(int i=1;i<vec.size();++i)
        if(max < vec[i])
            max = vec[i];
    return max;
}

int main(){

    int participants, budget, hotels, weekends;
    int costperhead, x, max;
    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");

    in>>participants>>budget>>hotels>>weekends;
    do{
        vector<int> total_cost(20,-99);
        vector<int> vec;
        
        for(int i=0;i<hotels;++i){
            in>>costperhead;
            for(int j=0;j<weekends;++j){
                in>>x;
                vec.push_back(x);
            }
            max = maximize(vec);
            if(max >= participants)
                total_cost[i] = participants*costperhead;
            vec.clear();
        }

        int min = 0;
        for(int i=0;i<total_cost.size(); ++i){
            if(total_cost[i] != -99 && total_cost[i]<budget)
                if(min < total_cost[i])
                    min = total_cost[i];
        }
        if(min == 0)
            out<<"stay home\n";
        else
            out<<min<<"\n";     
    }while(in>>participants>>budget>>hotels>>weekends);   

    out.close(); in.close();
}