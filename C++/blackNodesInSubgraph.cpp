#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    int vertices;
    vector<vector<int> > adjList;
    vector<int> color;
    stack<int> nodes;

    public:
    Graph(int V){
        vertices = V;
        adjList = vector<vector<int> >(V, vector<int>(1,0));
        color = vector<int>(V, 0);
        for(int i=0;i<V;++i){
            adjList[i][0] = i;
        }
    }

    void addColors(vector<int> c);
    void addEdge(int u, int v);
    void print();
    void printNodes();
    void DFS(int s, int b);
    bool dfs_visit(int node, vector<bool> &visited, int s, int b, int &counts, int &countb);
};

void Graph::addColors(vector<int> c){
    for(int i=0;i<vertices;++i)
        color[i] = c[i];
}

void Graph::addEdge(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::print(){
    for(int i=0;i<vertices;++i){
        cout<<adjList[i][0]<<" ";
        for(int j=1; j<adjList[i].size(); ++j)
            cout<<adjList[i][j]<<" ";
        cout<<"\n";
    }
}

void Graph::printNodes(){
    while(!nodes.empty()){
        cout<<nodes.top()<<" ";
        nodes.pop();
    }
}

void Graph::DFS(int s, int b){
    vector<bool> visited(vertices, false);
    int counts, countb;
    for(int node = 0; node < vertices; ++node){
        if(!visited[node]){
            counts = 0; countb = 0;
            //while(!nodes.empty())
            //    nodes.pop();
            if(dfs_visit(node, visited, s, b, counts, countb)){
                cout<<"Yes\n";
              //  printNodes();
                return;
            } 
            /*
            else {
                visited[node] = false;
                counts -= 1;
                nodes.pop();
                if(color[node] == 1)
                countb -= 1;
            }
            */
        }
    }
    cout<<"No\n";
}
bool Graph::dfs_visit(int node, vector<bool> &visited, int s, int b, int &counts, int &countb){
    if(color[node] == 1 && countb == b){
        visited[node] = true;
        return false;
    }
    counts += 1;
    if(counts == s && countb == b)
        return true;
    if(color[node] == 1)
        countb += 1;
    //nodes.push(node);
    for(int neighbour : adjList[node])
        if(!visited[neighbour])
            if(dfs_visit(neighbour, visited, s, b, counts, countb))
                return true;
    return false;
}

int main(){
    int t, u, v, n, q, no, s,b;
    vector<int> color;
    cin>>t;
    while(t--){
        cin>>n>>q;
        Graph g(n);
        for(int i=0;i<n-1;++i){
            cin>>u>>v;
            g.addEdge(u-1,v-1);
        }
        for(int i=0;i<n;++i){
            cin>>no;
            color.push_back(no);
        }
        g.addColors(color);
        while(q--){
            cin>>s>>b;
            g.DFS(s,b);
        }
        color.clear();
    }
}