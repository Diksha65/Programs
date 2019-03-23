#include<iostream>
#include<string>
#include<map>
using namespace std;

int hashfn(long long int rn){
	return rn % 5;
}

int main(){
	int n, index, q;
	long long int rn;
	string name;
	map<int, string> colleague;
	cin>>n;
	while(n--){
		cin>>rn>>name;
		index = hashfn(rn);
		colleague[index] = name;
	}
	cin>>q;
	while(q--){
		cin>>rn;
		index = hashfn(rn);
		cout<<colleague[index];
	}
}
