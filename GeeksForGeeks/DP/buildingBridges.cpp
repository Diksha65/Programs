//VARIATION ON LONGEST INCREASING SUBSEQUENCE
#include <bits/stdc++.h> 
using namespace std;


/*
    Store the coordinates of north and south in a pair in struct.
    Sort the pair on the basis of south bank and find the longest increasing subsequence for the north bank. That is the answer.
    OR
    Sort the pair on the basis of north bank and find the longest increasing subsequence for the south bank. That is the answer.

    In the following code, southern bank has been sorted and longest inreasing subsequence is found on the northern bank.
    Time complexity - O(n2)
 */
struct cityPairs {
    int north, south;
};

bool compare(struct cityPairs a, struct cityPairs b) {
    if(a.south == b.south)
        return a.north < b.north;
    return a.south < b.south;
}

int buildingbridges(struct cityPairs values[], int n) {
    sort(values, values+n, compare);

    vector<int> sequence(n, 1);

    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(values[i].north > values[j].north)
                sequence[i] = max(sequence[i], sequence[j]+1);
        }
    }

    int max = 0;
    for(int s : sequence)
        max = (max < s) ? s : max;
    return max;
}

int main() {
    int north[] = {8,1,4,3,5,2,6,7};
    int south[] = {1,2,3,4,5,6,7,8};

    struct cityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
    //{{8,1}, {1,2}, {4,3}, {3,4}, {5,5}, {2,6}, {6,7}, {7,8}};
    int n = sizeof(values)/sizeof(values[0]);
    cout<<buildingbridges(values, n)<<"\n";
}