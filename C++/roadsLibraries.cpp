#include<iostream>
#include<vector>
using namespace std;

class Graph{

    vector<vector<int>> adjList;

    public:
    Graph(int V){
        adjList.resize(V);
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> DFS(){
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
        return cnt;
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

void findMinCost(Graph graph, int clib, int croad){
    int cost = 0, c;
    vector<int> vec = graph.DFS();
    for(int i=0;i<vec.size(); ++i){
        int min = clib + (vec[i] - 1)*croad;
        for(int j = 2 ; j <= vec[i] ; ++j){
            c = j*clib + (vec[i] - j)*croad;
            if(c<min) min = c;
        }
        cost += min;
    }
    cout<<cost<<"\n";
}

int main(){
    int cases, n, m, clib, croad, u, v;
    cin>>cases;
    for(int j=cases;j>0;--j){
        cin>>n>>m>>clib>>croad;
        Graph graph(n);
        if(m == 0){
            cout<<clib*n<<"\n";
        } else {
            for(int i=0; i<m;++i){
                cin>>u>>v;
                graph.addEdge(u-1, v-1);
            }
            findMinCost(graph, clib, croad);
        }
    }
}