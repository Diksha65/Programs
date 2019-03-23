#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
void permute(string str, int start, int end){
    if(start == end)
        cout<<str<<"\n";
    for(int i=start; i<=end; ++i){
        swap(str[start], str[i]);
        permute(str, start+1, end);
        swap(str[start], str[i]);
    }
}

int main(){
    string s = "abca";
    permute(s, 0, s.size()-1);
}
*/

/*
void permute(string str, string out){
    if(str.size() == 0){
        cout<<out<<"\n";
        return;
    }

    for(int i=0;i<str.size();++i){
        permute(str.substr(1), out+str[0]);
        rotate(str.begin(), str.begin()+1, str.end());
    }
}

int main(){
    string str;
    permute("ABCA", "");

}
*/

void permute(string str){
    sort(str.begin(), str.end());
    do{
        cout<<str<<"\n";
    }while(next_permutation(str.begin(), str.end()));
}

int main(){
    permute("ABCA");
}