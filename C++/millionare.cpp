#include<iostream>
#include<vector>
#include<string>

int main(){
 
	string orig, chef;
	vector<int> points;
	int T, N, winner;
	cin>>T;
	while(T>0){
		cin>>N;
		points.resize(N+1, 0);	
		winner = 0;
		cin>>orig>>chef;
		for(int i=0;i<N; ++i){
			if(orig[N] == chef[N])
				++winner;
		}
		for(int i=0;i<N+1;++i)
			cin>>points[i];
		if(winner == N)
			cout<<points[N]<<endl;
		else{
			int ans=0;
			for(int i=0;i<=winner;++i)
				ans = max(ans, points[i]);
			cout<<ans<<endl;
		}
	}

}
