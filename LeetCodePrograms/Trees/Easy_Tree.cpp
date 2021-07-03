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
  
  //Calculate maxDepth or Height of tree
  int maxDepthUsingRecursion(Node *head);
  int maxDepthUsingIteratively();           //faster
  void maxDepth();
  
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
  
  //Sorted Array to BST
  void sortedArrayToBSTUsingIteration(vector<int>& nums);
  void sortedArrayToBSTUsingRecursion(vector<int>& nums);  //faster
  void sortedArrayToBST(vector<int>& nums);
  
  //Check if tree is Symmetric
  bool isSymmetricRecursion();
  bool isSymmetricIteration();  //faster. uses level order traversal.
  void isSymmetric();
  
  //Min Max in a BST
  int getMinimumFromBSTIterativly();
  int getMinimumFromBSTRecursively(Node *n);
  int getMaximumFromBSTIteratively();
  int getMaximumFromBSTRecursively(Node *n);
  void getMinMaxOfBST();
  void getMinMaxOfBT();
  
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
    cout<<"Height of tree (using recursion): "<<maxDepthUsingRecursion(root)<<"\n";

    //Using Iteration
    cout<<"Height of tree (using iteration): "<<maxDepthUsingIteratively()<<"\n";
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
    cout<<"Is symmetric (using recursion): "<<isSymmetricRecursion()<<"\n";
    
    //Using Iteration
    cout<<"Is symmetric (using iteration): "<<isSymmetricIteration()<<"\n";
}  

int Tree::getMinimumFromBSTIterativly() {
    Node *temp = root;
    while(temp->left!=NULL) {
        temp = temp->left;
    }
    return temp->info;
}

int Tree::getMinimumFromBSTRecursively(Node *n) {
    if(n->left == NULL) return n->info;
    return getMinimumFromBSTRecursively(n->left);
}

int Tree::getMaximumFromBSTIteratively() {
    Node *temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->info;
}

int Tree::getMaximumFromBSTRecursively(Node *n) {
    if(n->right == NULL) return n->info;
    return getMaximumFromBSTRecursively(n->right);
}

void Tree::getMinMaxOfBST() {
    if(root == NULL) {
        cout<<"The tree is empty.";
        return;
    }
    
    cout<<"Minimum element of BST --\n";
    cout<<"Iteratively: "<<getMinimumFromBSTIterativly()<<"\n";
    cout<<"Recursively: "<<getMinimumFromBSTRecursively(root)<<"\n";
    
    cout<<"Maximum element of BST --\n";
    cout<<"Iteratively: "<<getMaximumFromBSTIteratively()<<"\n";
    cout<<"Recursively: "<<getMaximumFromBSTRecursively(root)<<"\n";
}

void getMinMaxFromBTUtil(Node *n, int &min, int &max) {
    if(n!=NULL) {
        if(n->info < min) min = n->info;
        if(n->info > max) max = n->info;
        getMinMaxFromBTUtil(n->left, min, max);
        getMinMaxFromBTUtil(n->right, min, max);
    }
}

void Tree::getMinMaxOfBT() {
    if(root == NULL) {
        cout<<"The tree is empty.";
        return;
    }
    
    int min = INT_MAX, max = INT_MIN;
    getMinMaxFromBTUtil(root, min, max);
    cout<<"Minimum element of BT: "<<min;
    cout<<"\nMaximum element of BT: "<<max<<"\n";
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
    t.isValidBST();
    t.maxDepth();
    t.getMinMaxOfBST();
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
    t1.isValidBST();
    t1.maxDepth();
    t1.getMinMaxOfBT();
    t1.searchInBT(17);
   
   return 0;
}