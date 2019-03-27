#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int no){
    int digit, num=0;
    int original_no = no;
    while(no>0){
        digit = no % 10;
        num = (num*10) + digit;
        no = no/10;
    }
    if(original_no == num)
        return true;
    else
        return false;
}

int main(){
    int low, high, count=0;;
    cin>>low>>high;
    /*
    if(isPalindrome(19))
        cout<<"true\n";
    else 
        cout<<"false\n";
    */
    for(int i=low; i<=high; ++i){
        if(isPalindrome(i)){
            cout<<i<<"\n";
            count += 1;
        }
    }
    cout<<"Count="<<count<<"\n";
}