#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;
    int hotels, weekends, costperhead,x;
    cin>>hotels>>weekends;
    do{
        for(int i=0;i<hotels;++i){
            cin>>costperhead;
            for(int j=0;j<weekends;++j){
                cin>>x;
                vec.push_back(x);
            }
            cout<<"\n";
            for(int i=0;i<vec.size();++i){
                cout<<vec[i]<<"\t";
            }
            cout<<"\n";
            vec.clear();
        }
    }while(cin>>hotels>>weekends);
}