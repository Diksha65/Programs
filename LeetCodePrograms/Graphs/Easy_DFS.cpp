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
    
    //DFS
    void DFS(int source);
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

void DFSUtil(
    int source, 
    unordered_map<int, bool> &visited, 
    vector<int> &res, 
    map<int, vector<int>> adjList
    ) {
        
    visited[source] = true;
    
    for(auto x: adjList[source]) {
        if(!visited[x])
            DFSUtil(x, visited, res, adjList);
    }
    
    res.push_back(source);
}

void Graph::DFS(int source) {
    unordered_map<int, bool> visited;
    vector<int> res;
    visited[source] = true;
    res.push_back(source);
    
    for(auto node=adjList.begin(); node!=adjList.end(); node++) {
        if(!visited[node->first]) {
            DFSUtil(node->first, visited, res, adjList);
        }
    }
    
    cout<<"DFS: ";
    for(int x: res) {
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main()
{
   Graph g;
   g.addEdge(0, 1);
   g.addEdge(0, 9);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(9, 3);
   g.printGraph();
   g.DFS(2);
   return 0;
}