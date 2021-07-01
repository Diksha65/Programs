//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int t;
    //transpose
    for(int i=0;i<matrix.size();i++) {
        for(int j=i;j<matrix[i].size();j++) {
            t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
    
    //reverse
    for(int i=0;i<matrix.size();i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    
}

int main()
{
    vector<vector<int> > vec {
        {1,2,3},
        {4,5,6},
        {7,8,9}};
    rotate(vec);
    for(int i=0;i<vec.size();i++) {
        cout<<"[";
        for(int j=0;j<vec[i].size();j++) {
            cout<<vec[i][j]<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}