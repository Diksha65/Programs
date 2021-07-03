#include <bits/stdc++.h>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int info;
    Node *left;
    Node *right;
    Node(int x): info(x), left(NULL), right(NULL) {}
    Node(int x, Node *l, Node *r): info(x), left(l), right(r) {}
};

class Tree {
  
  Node *root = NULL;
  
  public:
  //Insertions
  void insertInBinaryTree(int n);
  void insertInBSTUtil(int n, Node* r);
  void insertInBST(int n);

  //Check if the tree is a BST
  bool isValidBSTUsingMinMax();             //fast
  bool isValidBSTUsingRecursion();          //faster
  bool isValidBSTUsingInOrderTraversal();   //fastest
  void isValidBST();
  
  //Traversals
  void inOrderTraversal(Node *r);           //used to get numbers in increasing order
  void preOrderTraversal(Node *r);          //used to create copy of tree          
  void postOrderTraversal(Node *r);         //used to delete the tree 
  void levelOrderTraversal();               //used to get the height of the tree   
  void printAllTraversals();
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

void Tree::insertInBSTUtil(int n, Node *r) {
    Node *newNode = new Node(n);
    if(r == NULL) {
        root = newNode;
        return;
    }
    
    //To be added to left subtree
    if (n < r->info) {
        if (r->left == NULL) {
            r->left = newNode;
            return;
        } else {
            insertInBSTUtil(n, r->left);
            return;
        }
    }
    
    //To be added to right subtree
    if (n >= r->info) {
        if (r->right == NULL) {
            r->right = newNode;
            return;
        } else {
            insertInBSTUtil(n, r->right);
            return;
        }
    }
    
    return;
}

void Tree::insertInBST(int n) {
    insertInBSTUtil(n, root);
}

bool isValidBSTUsingMinMaxUtil(Node *root, long long min, long long max) {
    if (root == NULL) return true;
    
    if (root->info <= min || root->info >= max) return false;
    
    return isValidBSTUsingMinMaxUtil(root->left, min, root->info) && isValidBSTUsingMinMaxUtil(root->right, root->info, max);
}

bool Tree::isValidBSTUsingMinMax() {
    //Time Complexity: O(n)
    //Space Complexity: O(1) if function stack is not considered else O(n)
    return isValidBSTUsingMinMaxUtil(root, LONG_MIN, LONG_MAX);
}

bool isValidBSTUsingRecursionUtil(Node *root, Node *l, Node *r) {
    if(root == NULL) return true;
    
    if(l!=NULL && root->info <= l->info) return false;
    
    if(r!=NULL && root->info >= r->info) return false;
    
    return isValidBSTUsingRecursionUtil(root->left, l, root) && isValidBSTUsingRecursionUtil(root->right, root, r);
} 

bool Tree::isValidBSTUsingRecursion(){
    return isValidBSTUsingRecursionUtil(root, NULL, NULL);
}

bool isValidBSTUsingInOrderTraversalUtil(Node *root, Node *&prev) {
    
    if(root == NULL) return true;
    
    if(!isValidBSTUsingInOrderTraversalUtil(root->left, prev)) return false;
    
    if(prev != NULL && root->info <= prev->info) return false;
    prev = root;
    
    return isValidBSTUsingInOrderTraversalUtil(root->right, prev);
}

bool Tree::isValidBSTUsingInOrderTraversal() {
    Node *prev = NULL;
    return isValidBSTUsingInOrderTraversalUtil(root, prev);
}

void Tree::isValidBST() {
    //Using MIN and MAX
    cout<<"Is Valid BST (using min & max): "<<isValidBSTUsingMinMax()<<"\n";
    
    //Using Recursion
    cout<<"Is Valid BST (using recursion): "<<isValidBSTUsingRecursion()<<"\n";
    
    //Using In Order Traversal
    cout<<"Is Valid BST (using in order traversal): "<<isValidBSTUsingInOrderTraversal()<<"\n";
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
    cout<<"\n";
}
  
int main()
{
   Tree t;
   t.insertInBST(8);
   t.insertInBST(3);
   t.insertInBST(10);
   t.insertInBST(1);
   t.insertInBST(6);
   t.insertInBST(14);
   t.insertInBST(4);
   t.insertInBST(7);
   t.insertInBST(13);
   t.printAllTraversals();
   t.isValidBST();
   
   return 0;
}