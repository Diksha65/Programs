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
  
  //Traversals
  void inOrderTraversal(Node *r);           //used to get numbers in increasing order
  void preOrderTraversal(Node *r);          //used to create copy of tree          
  void postOrderTraversal(Node *r);         //used to delete the tree 
  void levelOrderTraversal();               //used to get the height of the tree   
  void printAllTraversals();
  
  //Search in BT and BST
  bool searchInBSTIteratively(int n);
  bool searchInBSTRecursively(Node *r, int n);
  void searchInBST(int n);
  void searchInBT(int n);
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

bool Tree::searchInBSTIteratively(int n) {
    Node *temp = root;
    
    while(temp != NULL) {
        if(temp->info == n) {
            return true;
        } else if(temp->info > n) {
            temp = temp->left;    
        } else {
            temp = temp->right;
        }
    }
    
    return false;
}

bool Tree::searchInBSTRecursively(Node *r, int n) {
    if(r == NULL) return false;
    if(r->info == n) return true;
    if(r->left == NULL && r->right == NULL) return false;
    
    if(r->info > n) {
        return searchInBSTRecursively(r->left, n);
    } else {
        return searchInBSTRecursively(r->right, n);
    }
}

void Tree::searchInBST(int n) {
    if(root == NULL) {
        cout<<"The tree is empty\n";
        return;
    }
    
    cout<<"Searching result for "<<n<<" in BST (using recursion): "<<searchInBSTRecursively(root, n)<<"\n";
    cout<<"Searching result for "<<n<<" in BST (using iteration): "<<searchInBSTIteratively(n)<<"\n";
}
  
bool searchInBTUtil(Node *r, int n) {
    if(r!=NULL) {
        if(r->info == n) return true;
        searchInBTUtil(r->left, n);
        searchInBTUtil(r->right, n);
    }    
    return false;
}  

void Tree::searchInBT(int n) {
    if(root == NULL) {
        cout<<"The tree is empty\n";
        return;
    }
    
    cout<<"Searching result for "<<n<<" in BT: "<<searchInBTUtil(root, n);
}  


int main()
{
   //BST 
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
    t.searchInBST(15);
    cout<<"\n";
    
    //BT
    Tree t1;
    t1.insertInBinaryTree(10);
    t1.insertInBinaryTree(11);
    t1.insertInBinaryTree(9);
    t1.insertInBinaryTree(7);
    t1.insertInBinaryTree(12);
    t1.insertInBinaryTree(15);
    t1.insertInBinaryTree(8);
    t1.insertInBinaryTree(8);
    t1.printAllTraversals();
    t1.searchInBT(17);
   
   return 0;
}