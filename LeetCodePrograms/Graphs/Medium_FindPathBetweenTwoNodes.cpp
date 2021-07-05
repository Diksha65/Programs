#include <bits/stdc++.h>
#include <vector>
using namespace std;

//Graph using adjacency list
class Graph {
    map<int, vector<int>> adjList;
    
    public:
    
    //Adding edge to graph
    void addEdgeForDirectedGraph(int u, int v);
    void addEdgeForUnDirectedGraph(int u, int v);
    
    //Printing graph
    void printGraph();
    
    //Applications of DFS
    //2. Find path between 2 vertices
    void findPathInDirectedGraph(int u, int v);
    void findPathInUnDirectedGraph(int u, int v);
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

bool findPathInDirectedGraphUtil(map<int, vector<int>> adjList, unordered_map<int, bool> &visited, stack<int> &s, int u, int v) {
    
    visited[u] = true;
    s.push(u);
    
    for(auto x: adjList[u]) {
        if(!visited[x]) {
            if(x == v) {
                s.push(v);
                return true;
            };
            if(findPathInDirectedGraphUtil(adjList, visited, s, x, v)) return true;
        }
    }
    return false;
}

void Graph::findPathInDirectedGraph(int u, int v) {
    stack<int> s;
    unordered_map<int, bool> visited;
    
    s.push(u);
    visited[u] = true;
    bool found = false;
    for(auto node: adjList[u]) {
        if(!visited[node]) {
            if(node == v) {
                found = true;
                s.push(v);
                break;
            }
            if(findPathInDirectedGraphUtil(adjList, visited, s, node, v)) {
                found = true;
                break;
            }
        }
    }
    
    if(found) {
        cout<<"Path between "<<u<<" and "<<v<<" in directed graph : ";
        while(!s.empty()) {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<"\n";
    } else {
        cout<<"Path between "<<u<<" and "<<v<<" in directed graph is not found\n ";
    }
}

bool findPathInUnDirectedGraphUtil(map<int, vector<int>> adjList, unordered_map<int, bool> &visited, stack<int> &s, int u, int parent, int v) {
    
    visited[u] = true;
    s.push(u);
    
    for(auto x: adjList[u]) {
        if(x == parent) continue;
        
        if(!visited[x]) {
            if(x == v) {
                s.push(x);
                visited[x] = true;
                return true;
            }
            if(findPathInUnDirectedGraphUtil(adjList, visited, s, x, u, v)) 
                return true;
        }
    }
    
    return false;
}

void Graph::findPathInUnDirectedGraph(int u, int v) {
    stack<int> s;
    unordered_map<int, bool> visited;
    
    s.push(u);
    visited[u] = true;
    bool found = false;
    for(auto x: adjList[u]) {
        cout<<x<<"\n";
        if(!visited[x]) {
            if(x == v) {
                s.push(x);
                found = true;
                break;
            }
            
            if(findPathInUnDirectedGraphUtil(adjList, visited, s, x, u, v)) {
                found = true;
                break;
            }
        }
    }
    
    if(found) {
        cout<<"Path between "<<u<<" and "<<v<<" in undirected graph : ";
        while(!s.empty()) {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<"\n";
    } else {
        cout<<"Path between "<<u<<" and "<<v<<" in undirected graph is not found\n ";
    }
}

int main()
{
   //Directed Graphs
    Graph dg;
    dg.addEdgeForDirectedGraph(5, 2);
    dg.addEdgeForDirectedGraph(4, 0);
    dg.addEdgeForDirectedGraph(5, 0);
    dg.addEdgeForDirectedGraph(4, 1);
    dg.addEdgeForDirectedGraph(2, 3);
    dg.addEdgeForDirectedGraph(3, 1);
    dg.printGraph();
    dg.findPathInDirectedGraph(5,1);

    cout<<"\n\n";
    //Undirected Graphs
    Graph ug;
    ug.addEdgeForUnDirectedGraph(0,1);
    ug.addEdgeForUnDirectedGraph(1,2);
    ug.addEdgeForUnDirectedGraph(0,3);
    ug.addEdgeForUnDirectedGraph(3,4);
    ug.printGraph();
    ug.findPathInUnDirectedGraph(4,2);
    return 0;
}