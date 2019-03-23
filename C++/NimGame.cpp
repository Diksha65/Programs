#include<iostream>
using namespace std;

//CONSTANTS

const int N_COINS = 13;
const int MAX_MOVES = 3;
const int NO_GOOD_MOVE = -1;


enum Player { HUMAN, COMPUTER };

Player opponent(Player player){
    return (player == HUMAN) ? COMPUTER : HUMAN;
}

const Player STARTING_PLAYER = HUMAN;

class SimpleNim{
    public:

    void play(){
        n_coins = N_COINS;
        whoseturn = STARTING_PLAYER;
        while(n_coins > 1){
            cout<<"There are "<<n_coins<<" coins in the pile.\n";
            if(whoseturn == HUMAN)
                n_coins -= getUserMove();
            else{
                int nTaken = getComputerMove();
                cout<<"I'll take "<<nTaken<<endl;
                n_coins -= nTaken
            }
            whoseturn = opponent(whoseturn);
        }
        announceResult();
    }

    void printInstructions(){
        cout<<"Welcome to the game of Nim!\n";
    }

    private:
    int getComputerMove(){
        int nTaken = findGoodMove(n_coins);
        return (nTaken == NO_GOOD_MOVE) ? 1 : nTaken;
    }

    int findGoodMove(int n_coins){
        int limit = (n_coins<MAX_MOVE) ? n_coins : MAX_MOVE;
        for(int nTaken = 1; nTaken<=limit; nTaken++)
            if(isBadPosition(n_coins-nTaken)) return nTaken;
        return NO_GOOD_MOVE;
    }

    bool isBadPosition(int nCoins){
        if(nCoins == 1) return true;
        return findGoodMove(nCoins) == NO_GOOD_MOVE;
    }

    int getUserMove(){
        while(true){
            int nTaken;
            cout<<"How many would ou like?";
            cin>>nTaken;
            int limit = (n_coins < MAX_MOVE) ? n_coins : MAX_MOVE;
            if(nTaken > 0 && nTaken <= limit)
                return nTaken;
            
        }
    }
    
}
