#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int key, vector<int> vec, int start, int end){
    int mid = start + (end-start)/2 ;
    if(start>end) return -1;
    if(key == vec[mid]) return mid;
    else
        return key>vec[mid] ? binarySearch(key, vec, mid+1, end) : binarySearch(key, vec, start, mid-1);
    
}

int findInSortedArray(int key,vector<int> vec){
    int size = vec.size();
    return binarySearch(key, vec, 0, size-1);
}

int main(){
    int tmp[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vec(tmp, tmp+10);  
    int place = findInSortedArray(0, vec);
    if(place!=-1)
        cout<<"TRUE: "<<place;
}