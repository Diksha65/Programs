#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> vec){
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<" ";
    cout<<"\n";
}

/* BUBBLE SORT
void bubbleSort(vector<int> vec){
    for(int i=0;i<vec.size() - 1;++i){
        for(int j=0;j<vec.size(); ++j){
            if(vec[j] > vec[j+1])
                swap(vec[j], vec[j+1]);
        }
    }
    cout<<"Bubble Sort: ";
    print(vec);
}
*/

/* SELECTION SORT
int smallest(vector<int> vec, int index){
    int small = 99, pos = -1;
    for(int i = index; i<vec.size(); ++i){
        if(vec[i]<small){
            small = vec[i];
            pos = i;
        }
    }
    return pos;
}
void selectionSort(vector<int> vec){
    int smallIndex;
    for(int i=0; i<vec.size()-1;++i){
        smallIndex = smallest(vec, i);
        swap(vec[smallIndex], vec[i]);
    }
    cout<<"Selection Sort: ";
    print(vec);
}
*/

void merge(vector<int> &vec, int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int i, j=0, k=0;
    vector<int> left(n1,0);
    vector<int> right(n2,0);

    for(i=0;i<n1;++i)
        left[i] = vec[start + i];
    
    for(j=0;j<n2;++j)
        right[j] = vec[mid+j+1];
    
    j=0; k=0; i=start;

    while(j<n1 && k<n2){
        if(left[j] <= right[k])
            vec[i++] = left[j++];
        else if(left[j] > right[k])
            vec[i++] = right[k++];
    }

    while(j<n1)
        vec[i++] = left[j++];

    while(k<n2)
        vec[i++] = right[k++];
    
    print(vec);
}

void mergeSort(vector<int> &vec, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        mergeSort(vec, start, mid);
        mergeSort(vec, mid+1, end);
        merge(vec, start, mid, end);
    }
}

int main(){
    //vector<int> v = {5, 7, 2, 1, 4, 8 ,10, 3, 9, 6};
    vector<int> v = {5, 7, 2, 1};
    mergeSort(v, 0, v.size()-1);
}