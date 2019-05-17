#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* removeDuplicates(Node *root) {
    Node *temp = root;
    while(temp != NULL) {
        while(temp->next != NULL && temp->next->data == temp->data) {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    return root;
}

int main() {
    int T, N, ele;
    cin>>T;
    while(T--) {
        cin>>N;
        Node *head=NULL, *temp=head;
        while(N--) {
            cin>>ele;
            if(head==NULL) {
                head = temp = new Node(ele);
            } else {
                temp->next = new Node(ele);
                temp = temp->next;
            }
        }
        print(removeDuplicates(head));
        cout<<"\n";
    }
}