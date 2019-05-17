#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool balanced(string a) {
    stack<char> s;
    char  ch;
    for(int i=0;i<a.size();i++) {
	    if(a[i] == '[' || a[i] == '{' || a[i] == '(')
            s.push(a[i]);
	    else {
	        if(!s.empty()) {
	            ch = s.top();
	            if( (a[i] == ')' && ch == '(') || (a[i] == ']' && ch == '[') || (a[i] == '}' && ch == '{') )
	                s.pop();
	            else 
	                return 0;
	        } else 
	            return 0;
	    }
	}
    if(s.empty())
	    return 1;
	else
        return 0;
}

int main() {
	string a;
	int T;
	cin>>T;
	while(T--) {
	    cin>>a;
	    if(balanced(a)) 
	        cout<<"balanced\n";
	    else
	        cout<<"not balanced\n";
	}
}