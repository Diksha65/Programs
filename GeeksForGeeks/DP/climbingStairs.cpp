#include<bits/stdc++.h>
using namespace std;

//similar to coin change problem
int climbingStairs(vector<int> steps, int S) {
    vector<int> cnt(S+1,0);
    cnt[0] = 1;
    for(int s : steps) {
        for(int j=s;j<=S;j++) {
            cnt[j] += cnt[j-s];
        }
    }
    return cnt[S];
}

int main() {
    vector<int> steps = {1,2,3};
    int S = 12;
    cout<<climbingStairs(steps, S)<<"\n";
}