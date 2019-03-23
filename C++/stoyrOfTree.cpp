#include<iostream>
#include<vector>
using namespace std;

class Graph{

    vector<vector<int>> al;
    public:
    Graph(int v){
        al.resize(v);
    }

    void addEdge(int u, int v){
        al[u].push_back(v);
        al[v].push_back(u);
    }

    void printGraph(){
        for(int node=0; node < al.size() ++ node){
            cout<<"\n"<<node<<": ";
            for(int neighbour : al[node]){
                cout<<neighbour<<", ";
            }
        }
    }
};

int main(){

    int cases, nodes, u, v, g, k;
    cin>>cases;
    for(int i=0; i<cases; ++i){
        cin>>nodes;
        Graph g(nodes);
        for(int j=0;j<nodes-1; ++j){
            cin>>u>>v;
            g.addEdge(u-1,v-1);
        }
        cin>>g>>k;
        Graph g1(nodes);
        for(int j=0;j<g;++j){
            cin>>u>>v;
            g1.addEdge(u,v);
        }
        
    }
}