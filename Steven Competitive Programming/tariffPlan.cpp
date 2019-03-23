/*
Mile - 10 cents for 30 seconds(1-29s)
Juice - 15 cents for 60 seconds(1-59s)
*/

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int MileCost(vector<int> vec){
    int cost = 0; int quo, rem;
    for(int i=0;i<vec.size();++i){
        quo = vec[i]/30;
        rem = vec[i]%30 + 1;
        cost += quo*10;
        if(rem > 0)
            cost += 10;
    }
    return cost;

    /*	
	BETTER SOLUTION
	int cost = 0;
	for(int i=0;i<vec.size(); ++i)
	    cost += vec[i]/30 *10 + 10;	
	return cost;
    */
}

int JuiceCost(vector<int> vec){
    int cost = 0; int quo, rem;
    for(int i=0;i<vec.size();++i){
        quo = vec[i]/60;
        rem = vec[i]%60 + 1;
        cost += quo*15;
        if(rem > 0)
            cost += 15;
    }
    return cost;

    /*	
	BETTER SOLUTION
	int cost = 0;
	for(int i=0;i<vec.size(); ++i)
	    cost += vec[i]/60 *15 + 15;	
	return cost;
    */
}

int main(){
    int no_cases;
    int no_calls, call_duration;
    vector<int> vec;

    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");

    in>>no_cases;
    for(int i=0;i<no_cases;++i){
        in>>no_calls;
        for(int j=0;j<no_calls;++j){
            in>>call_duration;
            vec.push_back(call_duration);
        }
        int mile = MileCost(vec);
        int juice = JuiceCost(vec);

        if(mile<juice)
            out<<"Case "<<i+1<<": Mile "<<mile;
        else if(mile>juice)
            out<<"Case "<<i+1<<": Juice "<<juice;
        else if(mile == juice)
            out<<"Case "<<i+1<<": Mile Juice "<<juice;
        out<<"\n";

        vec.clear();
    }

    out.close(); in.close();
}
