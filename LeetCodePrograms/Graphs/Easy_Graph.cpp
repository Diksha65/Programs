#include <bits/stdc++.h>
#include <vector>
using namespace std;

//Graph using adjacency list (Mostly all for directed graph)
class Graph {
    map<int, vector<int>> adjList;
    
    public:
    
    //Adding edge to graph
    void addEdgeForDirectedGraph(int u, int v);
    void addEdgeForUnDirectedGraph(int u, int v);
    
    //Printing graph
    void printGraph();
    
    //BFS
    void BFS(int source);
    
    //DFS
    void DFS(int source);
    
    //Applications of DFS
    void isDirectedGraphCyclic();
    void isUnDirectedGraphCyclic();

    //Topological Sorting
    /*
        Possible only in a directed acyclic graph (DAG)
        1st vertex in a topological sort is always a vertex with in-degree as 0(a vertex with no incoming edges) 
    */
    void TopologicalSort(); 
};

void Graph::addEdgeForDirectedGraph(int u, int v) {
    //For directed graph
    adjList[u].push_back(v);
}

void Graph::addEdgeForUnDirectedGraph(int u, int v) {
    //For undirected graph
    adjList[u].push_back(v);
    adjList[v].push_back(u);
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
    unordered_map<int, bool> visited;
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

void DFSUtil(int source, unordered_map<int, bool> &visited, vector<int> &res, map<int, vector<int>> adjList) {
        
    visited[source] = true;
    res.push_back(source);
    
    for(auto x: adjList[source]) {
        if(!visited[x])
            DFSUtil(x, visited, res, adjList);
    }
    
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

bool isDirectedGraphCyclicUtil(map<int, vector<int>> adjList, unordered_map<int, bool> &visited, int node) {
    
    if(visited[node]) return true;
    
    visited[node] = true;
    for(auto x: adjList[node]) {
        if(isDirectedGraphCyclicUtil(adjList, visited, x)) 
            return true;
    }
    visited[node] = false;      //one extra step to get the cycle apart from DFS algorithm
    return false;
}

void Graph::isDirectedGraphCyclic() {
    //A graph has a cycle iff it has a back edge during DFS. 
    unordered_map<int, bool> visited;
    bool flag = false;
    for(auto node = adjList.begin(); node!=adjList.end(); node++) {
        if(isDirectedGraphCyclicUtil(adjList, visited, node->first)) {
            flag = true;
            break;
        }
    }
    if(flag) {
        cout<<"Directed Graph is cyclic\n";
    } else {
        cout<<"Directed Graph is not cyclic\n";
    }
}

bool isUnDirectedGraphCyclicUtil(map<int, vector<int>> adjList, unordered_map<int, bool> &visited, int node, int parent) {
    
    visited[node] = true;
    for(auto x: adjList[node]) {
        if(!visited[x]) {
            if(isUnDirectedGraphCyclicUtil(adjList, visited, x, node))
                return true;
        } else if(x != parent) {
            return true;
        }
    }
    return false;
}

void Graph::isUnDirectedGraphCyclic() {
    unordered_map<int, bool> visited;
    bool flag = false;

    for(auto node=adjList.begin(); node != adjList.end(); node++) {
        if(!visited[node->first]) {
            flag = flag || isUnDirectedGraphCyclicUtil(adjList, visited, node->first, -1);
        }
    }
    
    if(flag) {
        cout<<"Undirected Graph is cyclic\n";
    } else {
        cout<<"Undirected Graph is not cyclic\n";
    }
}

int main()
{
   //Directed Graphs
    Graph dg;
    dg.addEdgeForDirectedGraph(5, 2);
    dg.addEdgeForDirectedGraph(5, 0);
    dg.addEdgeForDirectedGraph(4, 0);
    dg.addEdgeForDirectedGraph(4, 1);
    dg.addEdgeForDirectedGraph(2, 3);
    dg.addEdgeForDirectedGraph(3, 1);
    dg.printGraph();
    dg.BFS(2);
    dg.DFS(0);
    dg.isDirectedGraphCyclic();

    cout<<"\n\n";
    //Undirected Graphs
    Graph ug;
    ug.addEdgeForUnDirectedGraph(0,1);
    ug.addEdgeForUnDirectedGraph(1,2);
    ug.addEdgeForUnDirectedGraph(0,3);
    ug.addEdgeForUnDirectedGraph(3,4);
    ug.printGraph();
    ug.BFS(2);
    ug.DFS(0);
    ug.isUnDirectedGraphCyclic();
    return 0;
}