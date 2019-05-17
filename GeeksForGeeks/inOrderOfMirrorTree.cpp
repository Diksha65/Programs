#include<iostream>
#include<map>
using namespace std;
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

struct Node *nl = new Node(0);
bool leafNode(Node *node) {
    if(node->left == NULL && node->right == NULL) 
        return true;
    else
        return false;
}
void mirror(Node* node) 
{
    if(node->left != NULL && node->right != NULL) {
         nl->left = node->left;
         nl->right = node->right;
         node->left = nl->right;
         node->right = nl->left;
    }
    if(!leafNode(node->left))
        mirror(node->left);
    if(!leafNode(node->right))
        mirror(node->right);
}

void inOrder(Node *node) {
    if(node == NULL)
        return 
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}

int main() {
    int T;
    struct Node *child;
    cin>>T;
    while(T--) {
        map<int, Node*> m;
        int N;
        cin>>N;
        struct Node *root=NULL;
        while(N--) {
            Node *parent;
            char lr;  int n1, n2;
            cin>>n1>>n2>>lr;
            if(m.find(n1) == m.end()) {
                parent = new Node(n1);
                m[n1] = parent;
                if(root == NULL) 
                    root = parent;
            } else 
                parent = m[n1];
            child = new Node(n2);
            if(lr = 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        mirror(root);
        inOrder(root);
        cout<<"\n";
    }
    return 0;
}

