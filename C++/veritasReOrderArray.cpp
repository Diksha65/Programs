#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int> &vec, int end, int start){
    int temp = vec[end];
    while(end != start){
        vec[end] = vec[--end];
    }
    vec[end] = temp;
}

void reorder(vector<int> vec){
    int j=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i] < 0){
            rotate(vec, i, j);
            j++;
        }
    }
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<" ";
    cout<<"\n";
}

int main(){
    int n;
    vector<int> vec;
    cout<<"Enter -1 to stop\n";
    while(cin>>n && n!=-1)
        vec.push_back(n);
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<" ";
    cout<<"\n";
    reorder(vec);
}