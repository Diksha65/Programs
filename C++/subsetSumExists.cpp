#include<iostream>
#include<Set>
using namespace std;

bool subsetSumExists(Set<int> & st, int target){
    if(st.isEmpty())
        return target == 0;
    else{
        int element = st.first();
        Set<int> rest = st - element;
        return subsetSumExists(rest, target) || subsetSumExists(rest, target - element);
    }
}

int main(){
    Set<int> st = {-2, 1,5,8,9,10,4};
    bool val = subsetSumExists(st, 15);
    if(val) cout<<val;
}