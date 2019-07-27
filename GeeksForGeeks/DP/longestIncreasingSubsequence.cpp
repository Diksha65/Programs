#include<iostream>
#include<vector>
using namespace std;

int lis(int arr[], int n) {
    vector<int> seq(n, 1);

    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i] > arr[j] && seq[i] < seq[j]+1)
                seq[i] = seq[j]+1;
        }
    }
    int max = 0;
    for(auto s : seq) 
        if(max < s) 
            max = s;
    return max;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<lis(arr, n)<<"\n";
}