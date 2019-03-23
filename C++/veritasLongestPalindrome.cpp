#include<iostream>
#include<vector>
#include<string>
using namespace std;

void print(string str, int start, int end){
    for(int i=start; i<=end;++i)
        cout<<str[i];
    cout<<"\n";
}

//Time Complexity O(n^2)
//Space Complexity O(n^2)
int longestpalindrome(string str){
    vector<vector<bool> > table(str.size(), vector<bool>(str.size(), false));
    int maxLength = 1;
    int start=0, n= str.size();
    for(int i=0;i<n;++i)
        table[i][i] = true;
    
    for(int i=0;i<n-1;++i){
        if(str[i] == str[i+1]){
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for(int k=3;k<=n;++k){
        for(int i=0;i<n-k+1;++i){
            int j = i+k-1;
            if(table[i+1][j-1] && str[i] == str[j]){
                table[i][j] = true;
                if(k > maxLength){
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    print(str, start, start+maxLength-1);
    return maxLength;
}

//Time Complexity O(n^2)
//Space Complexity O(n)
//Finds even length palindrome and odd length palindrome
int longestPalindrome(string str){
    int maxLength = 1, start;
    int low, high, len = str.size();

    for(int i=1; i<len; ++i){
        //Longest Even Length palindrome
        low = i-1;
        high = i;
        while(low >= 0 && high < len && str[low] == str[high]){
            if(high - low + 1 > maxLength){
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }

        //Longest Odd Length Palindrome
        low = i-1;
        high = i+1;
        while(low >= 0 && high < len && str[low] == str[high]){
            if(high - low + 1 > maxLength){
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }

    print(str, start, start+maxLength-1);
    return maxLength;
}

int main(){
    string str = "geeksforrofskeeg";
    cout<<longestpalindrome(str)<<"\n";
}