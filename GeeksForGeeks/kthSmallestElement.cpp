#include<iostream>
#include<vector>
using namespace std;

/*
void merge(vector<int> &arr, int l, int m, int r) {
    
    vector<int> left, right;
    int i=0, j=0, k=0;
    int n1 = m-l+1;
    int n2 = r-m;

    for(int i=0;i<n1;i++)
        left.push_back(arr[l+i]);
    for(int j=0;j<n2;j++)
        right.push_back(arr[m+1+j]);

    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) 
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i<n1) {
        arr[k++] = left[i++];
    }
    while(j<n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l<r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void kth_smallest(vector<int> arr, int N, int K) {
    
    mergeSort(arr, 0, N-1);
    cout<<"\n";
    for(int k=0;k<N;k++)  {
	        cout<<arr[k]<<" ";
	        //arr.push_back(a);
	    }
    cout<<"\n"<<arr[K-1]<<"\n";
}

int main()
{
	int T, N, K, a;
	cin>>T;
    while(T--) {
        cin>>N;
	    vector<int> arr(N,0);
	    for(int k=0;k<N;k++)  {
	        cin>>arr[k];
	    }
	    cin>>K;
	    kth_smallest(arr, N, K);
    }
	return 0;
}

*/

/*
***********QUICK SELECT************
Here QuickSort is used as a sorting algorithm. 
In QuickSort we pick a pivot element, move it to its correct position and partition the array around it. 
The idea is not to do complete quick sort but to stop at the pivot when pivot itself it kth smallest element.
Also not recur both left and right side of the pivot. btu recu for pone of them adccording to the position of pivot.
Worst case time complexity of this method is O(n2) but it works in O(n) on average.
*/
void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

//standard partition method of QuickSort(). It considers last element as pivot and moves all smaller elements to lefft of it and all larger to right.
int partition(vector<int> arr, int l, int r) { 
    int pivot = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= pivot) { 
            swap(&arr[i++], &arr[j]); 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int kth_smallest(vector<int> arr, int l, int r, int k) {
    if( k>0 && k <= r-l+1) {
        int pos = partition(arr, l, r);
        cout<<"pos "<<pos<<"\n";
        cout<<"k-1 "<<k-1<<"\n";
        cout<<"arr[pos] "<<arr[pos]<<"\n";
        if(pos-1 == k-1)
            return arr[pos];
        if(pos-1 > k-1)
            return kth_smallest(arr, l, pos-1, k);
        return kth_smallest(arr, pos+1, r, k-1-pos+l);
    }
    return -1;
}

int main() {
    int T, N, K, a;
	cin>>T;
    while(T--) {
        cin>>N;
	    vector<int> arr(N,0);
	    for(int k=0;k<N;k++)  {
	        cin>>arr[k];
	    }
	    cin>>K;
	    cout<<kth_smallest(arr, 0, N-1, K)<<"\n";
    }
	return 0;
}
