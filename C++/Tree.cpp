#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    node* left;
    node* right;
    node* parent;
    int info;
};

class BinarySearchTree {

    private:
        node* root;
    
    public:
        BinarySearchTree(){
            root = NULL;
        }
        inline bool isEmpty() const {
            return root == NULL;
        }
        node* search(int);
        node* minimumElement(node *n);
        node* maximumElement(node *);
        node* successorElement(node *);
        node* predecessorElement(node *);
        void insertNode(int);
        void transplant(node *, node *);
        void deleteNode(int);
        void inorderTreeWalk(node *);
        void preOrderTreeWalk(node *);
        void postOrderTreeWalk(node *);
        void printInorder();
        void printPreOrder();
        void printPostOrder();

        void createLinkList();
};

//Runs in O(h) time where h is the height of the tree
void BinarySearchTree::insertNode(int key){
    node *n = new node;
    n->info = key; 
    n->left = NULL; n->right = NULL; n->parent = NULL;
    node* y = NULL;
    node* x = root;
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
}
void BinarySearchTree::transplant(node *u, node *v){
    if(u->parent == NULL)
        root = v;
    else if( u == u->parent->left)
        u->parent->left = v;
    else 
        u->parent->right = v;
    if(v != NULL)
        v->parent = u->parent;
}
void BinarySearchTree::deleteNode(int key){
    node* z = search(key);
    node* y = NULL;
    if(z->left == NULL && z->right == NULL){
        if(z->parent->right == z)
            z->parent->right = NULL;
        else
            z->parent->left = NULL;
        delete z;
        
    }
    else if(z->left == NULL)
        transplant(z, z->right);
    else if(z->right == NULL)
        transplant(z, z->left);
    else{
        y = minimumElement(z->right);
        if(y->parent != z){
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y; 
        } else {
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }

}
node* BinarySearchTree::search(int key){
    node *tempRoot = root;
    // ITERATIVE PROCEDURE (works better in most of the computers)
    while(tempRoot != NULL){
        if(key == tempRoot->info)
            return tempRoot;
        else if(key < tempRoot->info)
            tempRoot = tempRoot->left;
        else 
            tempRoot = tempRoot->right;
    }
    return tempRoot;

    /* RECURSIVE PROCEDURE
    if(root == NULL || key == root->info)
        return root;
    if(key < root->info)
        return search(root->left, key);
    else 
        return search(root->right, key);
    */
}
node* BinarySearchTree::minimumElement(node* n){
    
    //ITERATIVE
    while(n->left != NULL)
        n = n->left;
    return n;

    /*RECURSIVE
    if(root->left == NULL)
        return root;
    return minimumElement(root->left);
    */
}
node* BinarySearchTree::maximumElement(node* n){
    //ITERATIVE
    while(n->right != NULL)
        n = n->right;
    return n;

    /*RECURSIVE
    if(root->right == NULL)
        return root;
    return maximumElement(root->right);
    */
}
node* BinarySearchTree::successorElement(node* root){
    if(root->right != NULL)
        return minimumElement(root->right);
    node* prnt = root->parent;
    while(prnt != NULL && root == prnt->right){
        root = prnt;
        prnt = prnt->parent;
    }
    return prnt;
}
node* BinarySearchTree::predecessorElement(node* root){
    if(root->left != NULL)
        return maximumElement(root->left);
    node* prnt = root->parent;
    while(prnt != NULL && root == prnt->left){
        root = prnt;
        prnt = prnt->parent;
    }
    return prnt;
}
void BinarySearchTree::inorderTreeWalk(node *root){
    if(root != NULL){
        inorderTreeWalk(root->left);
        cout<<root->info<<" ";
        inorderTreeWalk(root->right);
    }   
}
void BinarySearchTree::preOrderTreeWalk(node *root){
    if(root != NULL){
        cout<<root->info<<" ";
        preOrderTreeWalk(root->left);
        preOrderTreeWalk(root->right);
    }
}
void BinarySearchTree::postOrderTreeWalk(node *root){
    if(root != NULL){
        postOrderTreeWalk(root->left);
        postOrderTreeWalk(root->right);
        cout<<root->info<<" ";
    }
}
void BinarySearchTree::printInorder(){
    cout<<"Inorder:\n";
    inorderTreeWalk(root);
    cout<<"\n";
}
void BinarySearchTree::printPreOrder(){
    cout<<"Preorder:\n";
    preOrderTreeWalk(root);
    cout<<"\n";
}
void BinarySearchTree::printPostOrder(){
    cout<<"Postorder:\n";
    postOrderTreeWalk(root);
    cout<<"\n";
}

void BinarySearchTree::createLinkList(){
    node *temp = root;
    node *x = NULL;
    queue<node*> n1;
    queue<node*> n2;
    n1.push(temp);
    vector<LinkedList> vec;
    while(!n1.empty() || !n2.empty()){
        x = n1.front();
        n2.push(x->left);
        n2.push(x->right);
        n1.pop();

    }
    

}

int main(){
    BinarySearchTree bst;
    bst.insertNode(10);
    bst.insertNode(5);
    bst.insertNode(7);
    bst.insertNode(11);
    bst.insertNode(9);
    bst.insertNode(16);
    bst.insertNode(8);
    bst.insertNode(12);
    bst.insertNode(4);
    bst.insertNode(3);
    bst.deleteNode(10);
    bst.deleteNode(11);
    bst.printInorder();
}
