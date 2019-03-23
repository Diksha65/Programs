void Graph::topologicalSort(){
    stack<int> s;
    vector<bool> visitede(vertices, false);
    for(int node=0;node<vertices;++node){
        if(!visited[node])
            topologicalSortUtil(node, visited, s);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

void Graph::topologicalSortUtil(int node, vector<bool> visited, stack<int> s){
    visited[node] = true;
    for(int nei : adjList[nei])
        if(!visited[nei])
            topologiccalSortUtil(nei, visited, s);
    s.push(node);
}