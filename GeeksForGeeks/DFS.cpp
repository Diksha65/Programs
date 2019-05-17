#include<iostream>
#include<vector>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjList;
    public:
    Graph(int V) {
        vertices = V;
        adjList = vector<vector<int>>(V, vector<int>())
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

int main() {
    Graph 
}