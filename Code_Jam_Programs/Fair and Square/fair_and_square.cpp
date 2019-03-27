#include <iostream>
#include <cmath>
#include <vector>
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

int fair_and_square(int low, int high){
    int count = 0, b;
    for(int i=low; i <= high; ++i){
        if(isPalindrome(i)){
            b = sqrt(i);
            if(b == sqrt(i))
                if(isPalindrome(b))
                    count += 1;
        }
    }
    return count;
}

int main(){
    int cases, case_no=1, count, a;
    cin>>cases;
    long int low, high;
    for(int i=0;i<cases;++i){
        cin>>low>>high;    
        count=fair_and_square(low, high);
        cout<<"Case #"<<case_no<<": "<<count;
        case_no += 1;
        cout<<"\n";
    }
}