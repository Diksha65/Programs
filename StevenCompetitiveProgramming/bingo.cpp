#include<iostream>
#include<fstream>
#include<vector>
//#include<pair>
#include<algorithm>
#include<string>
using namespace std;

ofstream out; ifstream in;

void display(vector<vector<int> >card){
    out<<"\n";
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j)
            out<<card[i][j]<<"\t";
        out<<"\n";
    }
}

pair<int, int> noIsInPair(int n, const vector<vector<int> >card){
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
            if(card[i][j] == n)
                return make_pair(i,j);
    return make_pair(-1, -1);
}

bool hasWon(const vector<vector<int> > winCard){
    for(int i=0;i<5;++i){
        int flagH=0, flagV=0, flagD=0;
        for(int j=0;j<5;++j){
            if(winCard[i][j] == 1)
                flagH += 1;
            if(winCard[j][i] == 1)
                flagV += 1;
            if(i == j && winCard[i][j] == 1)
                flagD += 1;
        }

        if(flagD == 5 || flagV == 5 || flagH == 5)
            return true;
    }
    return false;
}

int bingo(int no,  vector<vector<int> >card, vector<vector<int> > &winCard){
    pair<int, int> coord;
    coord = noIsInPair(no, card);
    if(coord.first == -1 && coord.second == -1)
        return 0;
    else{ 
        winCard[coord.first][coord.second] = 1;
        if(hasWon(winCard)){
            //display(winCard);
            return 1;
        }
    }
    return 0;
}

int main(){
    int no, no_games;
    int count;
    vector<vector<int> >card(5, vector<int>(5,0));
    out.open("output.txt"); in.open("input.txt");

    in>>no_games;
    for(int g=0;g<no_games;++g){
        count = 0;
        vector<vector<int> >winCard(5, vector<int>(5,0));
        winCard[2][2] = 1;
        for(int i=0;i<5;++i)
            for(int j=0;j<5;++j)
                if( i == 2 && j == 2)
                    card[i][j] = 0;
                else {
                    in>>no;
                    card[i][j] = no;
                }
        //display(card);
        while(in>>no){
            count += 1;
            if(bingo(no, card, winCard) == 1)
                break;
        }
        out<<"BINGO after "<<count<<" numbers announced\n";
    
        //to remove the extra input
        string str;
        while(getline(in, str)){
            if(str.empty())
                break;
        }
    }
    out.close(); in.close();
}