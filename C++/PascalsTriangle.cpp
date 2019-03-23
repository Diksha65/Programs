#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<int> > vec){
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<vec[i].size();++j)
            cout<<vec[i][j]<<" ";
        cout<<"\n";
    }
}

void pascals_triangle(int n){
    vector<vector<int> > vec(n);
    vec[0].push_back(1);
    vec[1].push_back(1);
    vec[1].push_back(1);
    for(int i=2; i<n; ++i){
        for(int j=0;j<=i; j++){
            if(j-1 < 0) vec[i].push_back(vec[i-1][j]);
            else if(j+1 > i) vec[i].push_back(vec[i-1][j-1]);
            else vec[i].push_back(vec[i-1][j-1] + vec[i-1][j]);
        }
    }
    display(vec);
}

int main(){
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    pascals_triangle(n);
}