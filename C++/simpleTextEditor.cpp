#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    int cases, operation, k;
    string str="", InputString;
    stack<string> st;
    st.push("");
    cin>>cases;
    while(cases--){
        cin>>operation;
        switch(operation){
            case 1: cin>>InputString;
                    str += InputString;
                    st.push(str);
                    break;
            case 2: cin>>k;
                    str = str.erase(str.size()-k);
                    st.push(str);
                    break;
            case 3: cin>>k;
                    cout<<str[k-1]<<"\n";
                    break;
            case 4: st.pop();
                    str = st.top();
                    break;
            default: break;
        }
    }
}