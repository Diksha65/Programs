#include <bits/stdc++.h>
#include <vector>
using namespace std;

//Graph using adjacency list
class Graph {
    map<int, vector<int>> adjList;
    
    public:
    
    //Adding edge to graph
    void addEdge(int u, int v);
    
    //Printing graph
    void printGraph();
    
    //BFS
    void BFS(int source);
};

void Graph::addEdge(int u, int v) {
    //For undirected graph
    //adjList[u].push_back(v);
    //adjList[v].push_back(u);
    
    //For directed graph
    adjList[u].push_back(v);
}

void Graph::printGraph() {
    for(auto node=adjList.begin(); node!=adjList.end(); node++) {
        cout<<node->first<<"->";
        for(int x: node->second) {
            cout<<x<<",";
        }
        cout<<"\n";
    }
}

void Graph::BFS(int source) {
    map<int, bool> visited;
    vector<int> res;
    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        visited[temp] = true;
        for(int x: adjList[temp]) {
            if(!visited[x]) {
                q.push(x);
            }
        }
        res.push_back(temp);
    }
    cout<<"BFS: ";
    for(int x: res) {
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main()
{
   Graph g;
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);
   g.printGraph();
   g.BFS(2);
   return 0;
}