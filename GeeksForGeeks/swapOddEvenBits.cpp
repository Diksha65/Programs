#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string binaryNoOf(int n) {
    string bn = "";
    int num = n;
    int rem;
    while(num > 1) {
        rem = num%2;
        num = num/2;
        bn = to_string(rem) + bn;
    }
    bn = to_string(num) + bn;
    int diff = 8-bn.size();
    if(diff > 0) 
        for(int i=1;i<=diff;i++) 
            bn = '0'+bn;
    return bn;
}

void swap(char *a, char *b) {
    char *temp = a;
    a = b;
    b = temp;
}

string swapBinaryNumber(string n) {
    for(int i=0;i<n.size();i=i+2) {
        swap(n[i], n[i+1]);    
    }
    return n;
}

int DecimalNoOf(string n) {
    int num=0;
    for(int i=n.size()-1,j=0 ; i>=0 ; i--,j++) {
        num += pow(2,j)*((int)n[i]%48);
    }   
    return num;
}

int main()
 {
	int T, no;
	cin>>T;
	while(T--) {
	    cin>>no;
	    string bn = binaryNoOf(no);
	    string sn = swapBinaryNumber(bn);
        cout<<DecimalNoOf(sn)<<"\n";
	}
	return 0;
}