#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; 
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void solve(Node *root, int level, int &maxlevel) {
    if(level>maxlevel) {
        cout<<root->data<<" ";
        maxlevel=level;
    }
    if(root->left != NULL) 
        solve(root->left, level+1, maxlevel); 
    if(root->right != NULL) 
        solve(root->right, level+1, maxlevel);
}

void leftView(Node *root) {
    int maxl=0;
    solve(root, 1, maxl);
}

int main() {
    int T, N;
    struct Node *child;
    cin>>T;
    while (T--) {
        map<int, Node*> m;
        cin>>N;
        struct Node *root = NULL;
        while (N--) {
            Node *parent;
            char lr;
            int n1, n2;
            cin>>n1>>n2>>lr;
            if (m.find(n1) == m.end()) {
                parent = newNode(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            } else
                parent = m[n1];
            child = newNode(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2]  = child;
        }
        leftView(root);
        cout << endl;
    }
    return 0;
}