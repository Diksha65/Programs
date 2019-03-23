#include<iostream>
#include<limits>
#include<vector>
using namespace std;

//structure to represent node
struct node {
    int dest;
    int wt;
    struct node *next;
};

//structure to represent an adjacency list
struct AdjList {
    struct node *head;
};

//structure to represent graph(array of adj list)
struct Graph {
    int V;
    struct AdjList *list;
};

//utility func to create new node
struct node* newNode(int dest, int wt){
    struct node *nNode = (struct node*)malloc(sizeof(struct node));
    nNode->dest = dest;
    nNode->wt = wt;
    nNode->next = NULL;
    return nNode;
}

//uility funciton to create a graph of V vertices
struct Graph* createGraph(int V){
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->list = (struct AdjList*)malloc(V*sizeof(struct AdjList));
    for(int i=0; i<V; ++i)
        graph->list[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int wt){
    struct node* nNode = newNode(dest, wt);
    nNode->next = graph.list[src].head;
    graph->list[src].head = nNode;

    nNode = newNode(src, wt);
    nNode->next = graph->list[dest].head;
    graph.list[dest].head = nNode;
}

//structure to represent a min heap node
struct minHeapNode {
    int v;
    int dest;
};

//structure to represent a min heap
struct minHeap {
    int size;
    int capacity;
    int *pos;
    struct minHeapNode **array;
    
}