#include<iostream>
#include<vector>
using namespace std;

class Graph{
    vector<vector<int>> adjList;
    
    public:
    Graph(int v){
        adjList.resize(v);
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> DFS(){
        vector<bool> visited(adjList.size(), false);
        int count;
        vector<int> cnt;
        for(int node = 0; node < adjList.size(); ++node){
            if(!visited[node]){
                count = 1;
                dfs_visit(node, visited, count);
                cnt.push_back(count);
            }
        }
        return cnt;
    }

    void dfs_visit(int node, vector<bool> &visited, int &count){
        visited[node] = true;
        for(int neighbour: adjList[node])
            if(!visited[neighbour]){
                count += 1;
                dfs_visit(neighbour, visited, count);
            }
    }

    void calculatePairs(){
        vector<int> vec = DFS();
        long long int pair = 0;
        for(int i=0; i<vec.size(); ++i){
            for(int j = i+1; j<vec.size(); ++j){
                pair += vec[i]*vec[j];
            }
        }
        cout<<pair<<"\n";
    }
};

int main(){
    int N, P, u, v;
    cin>>N>>P;
    Graph graph(N);
    for(int i=0;i<P;++i){
        cin>>u>>v;
        graph.addEdge(u,v);
    }
    graph.calculatePairs();
}