// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph {
	vector<vector<int>> adjList;
	
	inline bool valid(int idx) const {
		return idx > -1 &&
			idx < adjList.size();
	}

public:
	Graph(int V) {
		adjList.resize(V);
	}

	void addEdge(int u, int v) {
		if (valid(u) && valid(v)) {
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		else {
			cerr << "Invalid Edge \n";
		}
	}

	void printGraph() {
		for (int node = 0; node < adjList.size(); ++node) {
			//print as originNode -> 
			cout << node << " : " ;
			for (int neighbour : adjList[node]) {
				cout << neighbour << ", ";
			}
			cout << "\n";
		}
	}

	void BFS(int source){
		queue<int> nodes;
        vector<bool> check(adjList.size(), false); 
		cout<<"BFS: ";
        nodes.push(source);
		while(!nodes.empty()){
            int node = nodes.front();
            if(check[node])
                break;
            check[node] = true;
            cout<<node<<", ";
            nodes.pop();
            for(int neighbour : adjList[node]){
                if(!check[neighbour])
                    nodes.push(neighbour);
            }
        }
	}

	void DFS(vector<int> &sort){
        vector<bool> check(adjList.size(), false);
        cout<<"\nDFS: ";
        for(int node = 0; node < adjList.size(); ++node){
            if(!check[node])
                dfs_visit(node, check, sort);
        }
    }

    void dfs_visit(int node, vector<bool> &check, vector<int> &sort){
        check[node] = true;
        for(int neighbour: adjList[node]){
            if(!check[neighbour])
                dfs_visit(neighbour, check, sort);
        }
        cout<<node<<", ";
		sort.push_back(node);
    }

	void topological_sort(){
		vector<int> sort;
		DFS(sort);
		cout<<"\nTopological sort: ";
		for( int i : sort)
			cout<<i<<", ";
	}
};

int main() {
	Graph graph(5);

	graph.addEdge(0, 1);
	graph.addEdge(0, 4);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(1, 4);
	graph.addEdge(2, 3);
	graph.addEdge(3, 4);

	graph.printGraph();
	graph.BFS(0);
	//graph.DFS();
	graph.topological_sort();
}