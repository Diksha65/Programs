#include<bits/stdc++.h>
using namespace std;

struct chainPairs {
    int first, second;
};

bool compare(chainPairs a, chainPairs b) {
    return a.first < b.first;
}
/*
    Time complexity - O(N2)
    We are not sorting the pairs so we will get the pairs in increasing order. not the maximum longest chain of possible pairs.
    Following only prints the length of the longest increasing chain
*/
int longestChain(chainPairs arr[], int n) {
    vector<int> seq(n,1);

    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i].first > arr[j].second) 
                seq[i] = max(seq[i], seq[j]+1);
        }
    }
    
    int max = 0;
    for(auto s : seq) 
        max = (max < s) ? s : max;
    return max;
}

/*
    To get the maximum possible pair chains, we will sort the pairs on the basis of their first element.
    Following also prints the longest chain.
*/
void maximumPairsChain(chainPairs arr[], int n) {
    sort(arr, arr+n, compare);

    vector<int> chainLength(n, 1);
    vector<vector<chainPairs>> chains(n);

    chains[0].push_back(arr[0]);

    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i].first > arr[j].second && chainLength[i] < chainLength[j] + 1) {
                chains[i] = chains[j];
                chainLength[i] = chainLength[j]+1;
            }
        }
        chains[i].push_back(arr[i]);
    }

    int max = 0,index = -1;
    for(int i=0;i<chainLength.size();i++) {
        if(chainLength[i] > max) {
            max= chainLength[i];
            index = i;
        }
    }
        
    for(auto pair : chains[index]) {
        cout<<"("<<pair.first<<","<<pair.second<<") ";
    }
    cout<<"\n";
}

int main() {
    chainPairs arr[] = //{{11, 20}, {10, 40}, {45, 60}, {39, 40}};
    { {5, 24}, {15, 25}, {27, 40}, {50, 60} };  
    int n = sizeof(arr)/sizeof(arr[0]);
    //cout<<longestChain(arr, n)<<"\n";
    maximumPairsChain(arr, n);
}