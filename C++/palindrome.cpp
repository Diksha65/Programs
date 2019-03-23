#include<iostream>
#include<string>
using namespace std;

bool isSubstringPalindrome(string str, int start, int end){
    if(start>=end)
        return true;
    else{
        cout<<"isSubstringPalindrome("<<str<<","<<start+1<<","<<end-1<<")\n";
        return str[start]==str[end] && isSubstringPalindrome(str, start+1, end-1);    
    }
}

bool isPalindrome(string str){
    int lwn = str.length();
    cout<<"isSubstringPalindrome("<<str<<",0,"<<lwn-1<<")\n";
    return isSubstringPalindrome(str, 0, lwn-1);
}

int main(){
    bool val = isPalindrome("level");
    if(val)
        cout<<"\ntrue\n";
    else
        cout<<"\nfalse\n";
}