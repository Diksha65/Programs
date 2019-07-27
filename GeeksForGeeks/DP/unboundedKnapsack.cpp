#include<bits/stdc++.h>
using namespace std;

/*
    Has one array with all the weights.
 */

int unboundedKnapsack(int W, int n, int val[], int wt[]) {
    
    //this vector stores the maximum value with capacity i
    vector<int> maxValue(W+1, 0);

    for(int i=0;i<=W;i++) {
        for(int j=0;j<n;j++) {
            if(wt[j] <= i) {
                maxValue[i] = max(maxValue[i], (val[j]+maxValue[i-wt[j]]));
            }
        }
    }
    return maxValue[W];
}

int main() {
    int W = 100; 
    int val[] = {10, 30, 20}; 
    int wt[] = {5, 10, 15}; 
    int n = sizeof(val)/sizeof(val[0]); 
  
    cout << unboundedKnapsack(W, n, val, wt)<<"\n"; 
}
