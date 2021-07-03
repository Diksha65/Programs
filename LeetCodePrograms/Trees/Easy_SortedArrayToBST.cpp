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
  //Sorted Array to BST
  void sortedArrayToBSTUsingIteration(vector<int>& nums);
  void sortedArrayToBSTUsingRecursion(vector<int>& nums);  //faster
  void sortedArrayToBST(vector<int>& nums);
};

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
    
    //Using Iteration
    cout<<"\nConverting sorted array to tree (using iteration): \n";
    sortedArrayToBSTUsingIteration(nums);
}

int main()
{
   cout << "Hello World" << endl; 
   
   return 0;
}