#include<iostream>
#include<vector>
using namespace std;

int hashFunc(char c){
    return c - 'a';
}

char reverseHashFunc(int i){
    return (char)i + 'a';
}

void printvec(vector<int> check){
    cout<<"\nvec\n";
    for(int i=0; i<check.size(); ++i){
        cout<<check[i]<<" ";
    }
    cout<<"\n";
}
/*
void firstNonRepeatingCharacter(vector<char> vec){
    vector<int> check(26, 0);
    for(int i=0;i<vec.size();++i){
        check[hashFunc(vec[i])] += 1; 
    }
    for(int i=0;i<check.size(); ++i){
        if(check[i] == 1){
            cout<<reverseHashFunc(i)<<" ";
            return;
        }
    }
    cout<<"-1 ";
}
*/
bool find(char ch, vector<char> &vec, int index){
    bool flag = false;
    for(int i=index;i<vec.size();++i)
        if(vec[i] == ch){
            vec[i] = '0';
            flag = true;
        }
    return flag;
}

void firstNonRepeatingCharacter(vector<char> vec){
    for(int i=0;i<vec.size();++i){
        if(vec[i] != '0')
            if(!find(vec[i], vec, i+1)){
                cout<<vec[i]<<" ";
                return;
        }
    }
    cout<<"-1 ";
}

int main(){
    int t, n;
    char ch;
    vector<char> vec;
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            cin>>ch;
            vec.push_back(ch);
            firstNonRepeatingCharacter(vec);
        }
        cout<<"\n";
        vec.clear();
    }
}