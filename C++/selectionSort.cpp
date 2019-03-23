#include<iostream>
#include<vector>
using namespace std;

int smallestElement(int index, vector<int> vec){
    int small = vec[index], pos = index;
    for(int i=index+1; i<vec.size(); i++){
        if(vec[i] < small){
            small = vec[i];
            pos = i;
        }
    }
    return pos;
}

void displayVector(vector<int> vec){
    cout<<"\n";
    for(int j=0;j<vec.size(); ++j){
        cout<<vec[j]<<"\t";
    }
    cout<<"\n";
}

void selectionsort(vector<int> vec){
    int smallestIndex;
    for(int i=0;i<vec.size(); ++i){
        smallestIndex = smallestElement(i, vec);
        int tmp = vec[i];
        vec[i] = vec[smallestIndex];
        vec[smallestIndex] = tmp;
    }
    displayVector(vec);
}

int main(){
    vector<int> vec(8,0);
    int val;
    cout<<"Enter the elements in the vector:";
    for(int i=0; i<8; i++){
        cin>>val;
        vec[i] = val;
    }
    selectionsort(vec);
}