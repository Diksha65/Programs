#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class Graph{
    int vertices;
    vector<vector<int> > adjList;
    public:
    Graph(int V){
        vertices = V;
        adjList = vector<vector<int> >(V, vector<int>(1,0));
        for(int i=0;i<V;++i){
            adjList[i][0] = i;
        }
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph(){

        for(int i=0;i<adjList.size(); ++i){
            cout<<adjList[i][0];
            for(int j=1;j<adjList[i].size(); ++j){
                cout<<"->"<<adjList[i][j];
            }
            cout<<"\n";
        }
    }

	void BFS(int source){
		queue<int> nodes;
        vector<int> distance(vertices, 999);
        vector<bool> check(vertices, false); 
        nodes.push(source);
        distance[source] = 0;
        cout<<"BFS: ";
		while(!nodes.empty()){
            int node = nodes.front();
            if(check[node])
                break;
            check[node] = true;
            cout<<node<<", ";
            nodes.pop();
            for(int neighbour : adjList[node]){
                if(!check[neighbour]){
                    nodes.push(neighbour);
                    distance[neighbour] = distance[node] + 1;
                }
            }
        }
        cout<<"\n";
	}

     void DFS(){
        vector<bool> check(adjList.size(), false);
        int count;
        vector<int> cnt;
        for(int node = 0; node < adjList.size(); ++node){
            if(!check[node]){
                count = 1;
                dfs_visit(node, check, count);
                cnt.push_back(count);
            }
        }
        for(int i:cnt)
            cout<<i<<" ";
    }

    void dfs_visit(int node, vector<bool> &check, int &count){
        check[node] = true;
        for(int neighbour: adjList[node])
            if(!check[neighbour]){
                count += 1;
                dfs_visit(neighbour, check, count);
            }
    }

};

int main(){
    /*
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(0,4);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(1,4);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
*/

    Graph graph(4);
	graph.addEdge(0,2);
    
    graph.printGraph();
    //graph.BFS();
    graph.DFS();

}