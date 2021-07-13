#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
vec = [3,10,2,1,20]
Longest Increasing Subsequence of vec = [3, 10, 20] (size 3)

vec = [50, 3, 10, 7, 40, 80]
Longest Increasing Subsequence of vec = [3, 10, 40, 80] or [3, 7, 40, 80] (size 4)
*/

//2 ways:
//1. Iterative
//2. DP

//Time Complexity: O(n2) Space Complexity: O(n)
void LISIterative(vector<int> vec) {
   
    int n = vec.size();
    vector<int> result(n, 0);
   
    result[0] = 1;
   
    for(int i=1;i<n;i++) {
        result[i] = 1;
        for(int j=0;j<i;j++) {
            if(vec[j] < vec[i] && result[i] < result[j] +1) {
                result[i] = 1+result[j];
            }
        }
    }
   
    int max = INT_MIN;
    int index = -1;
    for(int i=0;i<result.size();i++) {
        max = result[i]>max ? result[i] : max;
        index = i;
    }
   
    cout<<"\nSize: "<<max<<"\n";
    cout<<"List: ";
    for(int i=index; i>=0;i--) {
        if(max != 0 && result[i] == max) {
            cout<<vec[i]<<" ";
            max = max-1;
        }
    }
}

//TimeComplexity: O(nlogn) Space Complexity: O(n)
void LISUsingDPAndBinarySearch(vector<int> vec) {
    vector<int> res;
    res.push_back(vec[0]);
   
    for(int i=1;i<vec.size();i++) {
        if(res.back() < vec[i]) {
            res.push_back(vec[i]);
        } else {
            int index = lower_bound(res.begin(), res.end(), vec[i]) - res.begin();
            res[index] = vec[i];
        }
    }
   
    cout<<"\nSize: "<<res.size()<<"\n";
    cout<<"List: ";
    for(auto x: res) {
        cout<<x<<" ";
    }
}

int main()
{
   vector<int> vec{50, 3, 10, 7, 40, 80};
   
   cout<<"LIS for the given vector is (Using iteration): ";
   LISIterative(vec);
   
   cout<<"\nLIS for the given vector is (Using DP): ";
   LISUsingDPAndBinarySearch(vec);
   
   return 0;
}
