#include<iostream>
#include<vector>

int calculate(vector<int> vec, long long int left, long long int right, long long int modulo){
	int mult = 1;
	for(int i=left-1; i<=right-1; ++i)
		mult* = vec[i];
	return mult % modulo;
}

int main(){
	
	long long int n,games, left, right, modulo;
	cin>>n;
	vector<int> vec(n, 0);
	for(int i=0;i<n;++i)
		cin>>vec[n];
	cin>>games;
	while(games--){
		cin>>left>>right>>modulo;
		cout<<calculate(vec, left, right, modulo);
	}
}
