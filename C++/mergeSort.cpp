#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &vec, int start, int mid, int end){
    int nr = end - mid;
    int nl = mid - start + 1;
    vector<int> left(nl), right(nr);
    for(int i=0;i<nl;++i){
        left[i] = vec[start + i];
    }
    for(int i=0;i<nr;++i){
        right[i] = vec[mid + i];
    }
    int i=0, j=0, k;
    for(k=start;k<end;){
        if(left[i]<right[j])
            vec[k++] = left[i++];
        else 
            vec[k++] = right[j++];
    }
    if(i<nl)
        vec[k++] = left[i++];
    else if(j<nr)
        vec[k++] = right[j++];
    
}

void merge_sort(vector<int> &vec, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        merge_sort(vec, start, mid);
        merge_sort(vec, mid+1, end);
        merge(vec, start, mid, end);
    }
}

int main(){

    int n = 5, no;
    vector<int> vec;
    while(n--){
        cin>>no;
        vec.push_back(no);
    }
    merge_sort(vec, 0, vec.size());
    for(int i : vec){
        cout<<i<<" ";
    }
}