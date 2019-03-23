#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
/*
struct node{
    node* left;
    node* right;
    node* parent;
    int info;
};

class BinarySearchTree{

    private:
        node* root;

    public:
    BinarySearchTree(){
        root = (node *)malloc(sizeof(node)); 
        root = NULL;
    }
    void insertNode(int);
};

void BinarySearchTree::insertNode(int key){
    
    node *n = (node *)malloc(sizeof(node));
    n->info = key; n->left = NULL; n->right = NULL; n->parent = NULL;
    cout<<n->info<<"\n";
    node* y; 
    node* x=root;
    while(x != NULL){
        y = x;
        if(n->info < x->info)
            x = x->left;
        else 
            x = x->right;
    }
    n->parent = y;
    if(y == NULL)
        root = n;
    else if(n->info < y->info)
        y->left = n;
    else    
        y->right = n;
    cout<<root->right<<"\n";
    cout<<"root"<<root->info<<"\n";
}
*/

int main(){
    //BinarySearchTree bst;
    //bst.insertNode(5);
    //bst.insertNode(10);
    cout<<abs(2-1);
    cout<<abs(1-2);
}