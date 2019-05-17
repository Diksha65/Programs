#include<iostream>
#include<string>
using namespace std;

bool rotateByTwoPlace(string a, string b) {
    int j=0, cnt=0;
    if(a.size() != b.size())
        return false;
    for(int i=0;i<a.size();i++) {
        if(a[i] == b[j] || a[j] == b[i]) {
            j++;
        } else {
            cnt++; 
        }
    }
    if(cnt==2)
        return true;
    else
        return false;
}

int main()
 {
	int T;
	string a, b;
	cin>>T;
	while(T--) {
	    cin>>a>>b;
	    if(rotateByTwoPlace(a,b))
	        cout<<"1\n";
	    else 
	        cout<<"0\n";
	}
	return 0;
}