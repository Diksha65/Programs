#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity = O(N2) 
*/

int maxSumIncreasingSubsequence(int arr[], int n) {
    vector<int> maxSum(n);
    for(int i=0;i<n;i++) {
        maxSum[i] = arr[i];
    }

    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i]>arr[j] && maxSum[i] < maxSum[j]+arr[i]) 
                maxSum[i] = maxSum[j] + arr[i];
                //OR
                //maxSum[i] = max(maxSum[i] , maxSum[j] + arr[i]);
        }
    }

    int max = 0;
    for(auto sum : maxSum) 
        max = (max < sum) ? sum : max;
    return max;
}

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    cout<<maxSumIncreasingSubsequence(arr, n)<<"\n";
}