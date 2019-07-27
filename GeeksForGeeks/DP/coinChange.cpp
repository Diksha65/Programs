#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount, int n) {
    vector<int> amt(amount+1,0);
    amt[0] = 1;
    for(auto coin : coins) {
        for(int a = coin; a < amount+1; a++ ) {
            amt[a] = amt[a] + amt[a-coin];
        }
        /* 
                    OR
        for(int a=1;a<amount+1;a++) {
            if(coin <= amount) {
                amt[a] = amt[a] + amt[a-coin];            
            }
        }
         */
    }
    return amt[5];
}

int main() {
    vector<int> coins = {1,2,5};
    int amount = 12;

    int n = coins.size();
    cout<<coinChange(coins, amount, n)<<"\n";
}