//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/

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
  //Traversals
  void inOrderTraversal(Node *r);           //used to get numbers in increasing order
  void preOrderTraversal(Node *r);          //used to create copy of tree          
  void postOrderTraversal(Node *r);         //used to delete the tree 
  void levelOrderTraversal();               //used to get the height of the tree   
  void printAllTraversals();
  
  //Sorted Array to BST
  void sortedArrayToBSTUsingIteration(vector<int>& nums);
  void sortedArrayToBSTUsingRecursion(vector<int>& nums);  //faster
  void sortedArrayToBST(vector<int>& nums);
};

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

Node* sortedArrayToBSTUtil(int begin, int end, Node *root, vector<int>& nums) {
    if(begin > end) return NULL;
    
    int mid = begin + (end-begin)/2;
    Node *newNode = new Node(nums[mid]);
    newNode->left = sortedArrayToBSTUtil(begin, mid-1, newNode, nums);
    newNode->right = sortedArrayToBSTUtil(mid+1, end, newNode, nums);
    root = newNode;
    return root;
}

void Tree::sortedArrayToBSTUsingRecursion(vector<int>& nums) {
    root = sortedArrayToBSTUtil(0, nums.size()-1, NULL, nums);
}

Node* insertForSortedArrayToBST(int n, Node *node) {
    if(node == NULL) {
        Node *newNode = new Node(n);
        return newNode;
    }
    
    if(n < node->info) {
        node->left = insertForSortedArrayToBST(n, node->left);
    } else {
        node->right = insertForSortedArrayToBST(n, node->right);
    }
    return node;
}
    
void Tree::sortedArrayToBSTUsingIteration(vector<int>& nums) {
    if(nums.empty()) {
        root = NULL;
        return;
    }
        
    int n = nums.size();
    int mid = n/2; 
    
    Node *root = new Node(nums[mid]);
    Node *temp = root;
    
    for(int i=0;i<n;i++) {
        if(i == mid) continue;
        insertForSortedArrayToBST(nums[i], temp);
    }
}

void Tree::sortedArrayToBST(vector<int>& nums) {
    //Using Recursion
    cout<<"\nConverting sorted array to tree (using recusrion): \n";
    sortedArrayToBSTUsingRecursion(nums);
    printAllTraversals();
    
    //Using Iteration
    cout<<"\nConverting sorted array to tree (using iteration): \n";
    sortedArrayToBSTUsingIteration(nums);
    printAllTraversals();
}

int main()
{
   vector<int> vec {1,3,4,6,7,8,10,13,14};
   Tree t;
   t.sortedArrayToBST(vec);
   
   return 0;
}