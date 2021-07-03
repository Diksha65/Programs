//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/627/

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

  //Check if tree is Symmetric
  bool isSymmetricRecursion();
  bool isSymmetricIteration();  //faster. uses level order traversal
  void isSymmetric();
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

bool isSymmetricRecursionUtil(Node *left, Node *right) {
    if(left == NULL || right == NULL) return left==right;
    
    if(left->info != right->info) return false;
    
    return isSymmetricRecursionUtil(left->left, right->right) && isSymmetricRecursionUtil(left->right, right->left);
}
 
bool Tree::isSymmetricRecursion() {
    return isSymmetricRecursionUtil(root->left, root->right);
}

bool Tree::isSymmetricIteration() {
    queue<Node*> q;
    Node *temp;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        vector<int> vec;
        for(int i=0;i<n;i++) {
            temp = q.front();
            q.pop();
            if(temp != NULL) {
                q.push(temp->left);
                q.push(temp->right);
                vec.push_back(temp->info);
            } else {
                vec.push_back(INT_MAX);
            }
        }
        int begin = 0, end = vec.size()-1;
        while(begin < end) {
            if(vec[begin++] != vec[end--]) return false;
        }
    }
    return true;
}
 
void Tree::isSymmetric() {
    //Using Recursion
    cout<<"\nIs symmetric (using recursion): "<<isSymmetricRecursion()<<"\n";
    
    //Using Iteration
    cout<<"Is symmetric (using iteration): "<<isSymmetricIteration()<<"\n";
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
   t.isSymmetric();
   
   return 0;
}