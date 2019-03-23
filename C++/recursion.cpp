#include<iostream>
#include<string>
using namespace std;

bool findNumber(int num, int n){
    if(n < num){
        if(findNumber(num, n*3)){
            cout<<"( "<<n<<" * 3)";
            return true;
        }
        if(findNumber(num, n+5)){
            cout<<"( "<<n<<" + 5)";
            return true;
        }
    } else if(n == num)
        return true;
    else    
        return false;
}

/*
string find(int target, int start, string history) {
    if(start == target)
        return history;
    else if(start > target)
        return "";
    else {
        return find(target, start + 5, "(" + history + " + 5 )") || 
               find(target, start * 3, "(" + history + " * 3 )");
    }
}
*/
int main() {
    int n;
    cin>>n;
    if(!findNumber(n, 1))
        cout<<"Not possible\n";

}
