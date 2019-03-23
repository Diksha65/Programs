#include<iostream>
#include<stack>
#include<vector>
#include<stack>
#include<map>
using namespace std;

map<int, stack<int> > a;
map<int, stack<int> > b;

vector<int> primeNos(int Q){
    int count, primeCount=0, number = 1;
    vector<int> pr;
    while(primeCount != Q){
        count = 0; 
        number += 1;
        for(int i = 1; i <= number ; i++)
            if(number % i == 0)
                count += 1;
        if(count == 2){
            pr.push_back(number);
            primeCount += 1;
        }
    }
    return pr;
}

void waiter(int iter, vector<int> primes){
    int no;
    for(int i=1;i<=iter;i++){
        while(!a[i-1].empty()){
            no = a[i-1].top();
            if(no % primes[i-1] == 0)
                b[i].push(no);
            else   
                a[i].push(no);
            a[i-1].pop();
        }
    }
    
}

void print(){
    for(auto &p : b)
        while(!p.second.empty()){
            cout<<p.second.top()<<"\n";
            p.second.pop();
        }
    
    for(auto &p : a)
        while(!p.second.empty()){
            cout<<p.second.top()<<"\n";
            p.second.pop();
        }
}

int main(){
    int N, Q, no;
    cin>>N>>Q;
    vector<int> primes = primeNos(Q);
    while(N--){
        cin>>no;
        a[0].push(no);
    }
    waiter(Q, primes);
    print();
}
