#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &vec, int start, int finish){
    int pivot = vec[start];
    int lh = start + 1;
    int rh = finish;
    while(true){
        while(lh < rh && vec[rh] >= pivot) rh--;
        while(lh < rh && vec[lh] < pivot) lh++;
        if(lh == rh) break;
        int tmp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = tmp;
    }
    if(vec[lh] >= pivot) return start;
    vec[start] = vec[lh];
    vec[lh] = pivot;
    return lh;
}

void quickSort(vector<int> &vec, int start, int finish){
    if(start >= finish) return;
    int boundary = partition(vec, start, finish);
    quickSort(vec, start, boundary-1);
    quickSort(vec, boundary+1, finish);
}

void display(vector<int> vec){
    cout<<"\n";
    for(int j=0;j<vec.size(); ++j){
        cout<<vec[j]<<"\t";
    }
    cout<<"\n";
}

void sort(vector<int> &vec){
    quickSort(vec, 0, vec.size()-1);
    display(vec);
}

int main(){
    vector<int> vec(8,0);
    int val;
    cout<<"Enter the elements in the vector:";
    for(int i=0; i<8; i++){
        cin>>val;
        vec[i] = val;
    }
    sort(vec);
}