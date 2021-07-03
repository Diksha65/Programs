//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/

#include <bits/stdc++.h>
#include <math.h>
#include <queue>
using namespace std;

struct Node {
    int info;
    Node *left;
    Node *right;
    Node(int x): info(x), left(NULL), right(NULL) {}
    Node(int x, Node *l, Node *r): info(x), left(l), right(r) {}
};

class Tree {
  
  Node *root;
  
  public:
  //Insertions
  void insertInBinaryTree(int n);

  //Traversals
  void inOrderTraversal(Node *r);           //used to get numbers in increasing order
  void preOrderTraversal(Node *r);          //used to create copy of tree          
  void postOrderTraversal(Node *r);         //used to delete the tree 
  void levelOrderTraversal();               //used to get the height of the tree   
  void printAllTraversals();

  //Calculate maxDepth or Height of tree
  int maxDepthUsingRecursion(Node *head);
  int maxDepthUsingIteratively();           //faster
  void maxDepth();
};

void Tree::insertInBinaryTree(int n) {
    Node *newNode = new Node(n);
    if(root == NULL) {
        root = newNode;
        return;
    }
    
    queue<Node*> q;
    Node *temp;
    q.push(root);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        
        if(temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }
        
        if(temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}

void Tree::inOrderTraversal(Node *r) {
    //Time Complexity: O(n)
    //Space Complexity: O(1) if function stack is not considered else O(h) where h:height of tree.
    if(r != NULL) {
        inOrderTraversal(r->left);
        cout<<r->info<<" ";
        inOrderTraversal(r->right);
    }
}

void Tree::preOrderTraversal(Node *r) {
    //Time Complexity: O(n)
    //Space Complexity: O(1) if function stack is not considered else O(h) where h:height of tree.
    if(r != NULL) {
        cout<<r->info<<" ";
        preOrderTraversal(r->left);
        preOrderTraversal(r->right);
    }
}

void Tree::postOrderTraversal(Node *r) {
    //Time Complexity: O(n)
    //Space Complexity: O(1) if function stack is not considered else O(h) where h:height of tree.
    if(r != NULL) {
        postOrderTraversal(r->left);
        postOrderTraversal(r->right);
        cout<<r->info<<" ";
    }
}

void Tree::levelOrderTraversal(){
    if(root == NULL) return;
    
    queue<Node*> q;
    Node *temp;
    q.push(root);
    int n;
    while(!q.empty()) {
        n = q.size();
        for(int i=0;i<n;i++) {
            temp = q.front();
            q.pop();
            cout<<temp->info<<" ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
    temp = NULL;
}

void Tree::printAllTraversals() {
    //In Order Traversal
    cout<<"\nIn Order Traversal:\n";
    inOrderTraversal(root);
    
    //Pre Order Traversal
    cout<<"\nPre Order Traversal:\n";
    preOrderTraversal(root);
    
    //Post Order Traversal
    cout<<"\nPost Order Traversal:\n";
    postOrderTraversal(root);
    
    //Level Order Traversal
    cout<<"\nLevel Order Traversal:\n";
    levelOrderTraversal();
}

int Tree::maxDepthUsingRecursion(Node *head) {
    //Time Complexity: O(n)
    if(head == NULL) return 0;
    if(head->left == NULL && head->right == NULL) return 1;
    
    return 1+ max(maxDepthUsingRecursion(head->left), maxDepthUsingRecursion(head->right));
}

int Tree::maxDepthUsingIteratively() {
    //Height = #Levels
    //Faster than recursive approach
    if(root == NULL) return 0;
    
    int height = 0;
    queue<Node*> q;
    Node *temp;
    q.push(root);
    
    while(!q.empty()) {
        int n= q.size();
        for(int i=0;i<n;i++) {
            temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        height += 1;
    }
    return height;
}

void Tree::maxDepth() {
    //Using Recursion
    cout<<"\nHeight of tree (using recursion): "<<maxDepthUsingRecursion(root)<<"\n";

    //Using Iteration
    cout<<"Height of tree (using iteration): "<<maxDepthUsingIteratively()<<"\n";
}

int main()
{
   Tree t;
   t.insertInBinaryTree(10);
   t.insertInBinaryTree(11);
   t.insertInBinaryTree(9);
   t.insertInBinaryTree(7);
   t.insertInBinaryTree(12);
   t.insertInBinaryTree(15);
   t.insertInBinaryTree(8);
   t.insertInBinaryTree(8);
   t.printAllTraversals();
   t.maxDepth(); 
   return 0;
}