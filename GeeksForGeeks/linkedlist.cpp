#include<iostream>
using namespace std;

class Node {
    int data;
    Node *next;
    public:
        void pairWiseSwap(Node *head);
        int getMiddle(Node *head);
        void append(struct Node** head, struct Node** tail, int a);
};

void Node::pairWiseSwap(Node *head)
{
    struct Node *n = head;
    while(n!=NULL && n->next != NULL) {
        swap(n->data, n->next->data);
        n=n->next->next;
    }
}

int Node::getMiddle(Node* head) {
    Node *fast = head, *slow=head;
    while(fast != NULL && fast->next!=NULL) {
        if(fast->next->next == NULL)
            fast = fast->next;
        else 
            fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

void Node::append(struct Node** head, struct Node** tail, int a) {
    struct Node *n = new Node;
    n->data = a;
    n->next = NULL;
    if(*head == NULL) 
        *head = n;
    else
        (*tail)->next = n;
    *tail = n;
}

int main() {
    int T, N, a;
    cin>>T;
    Node *head = NULL, *tail = NULL;
    cin>>N;
    while(N--) {
        cin>>a;
        append(&head, &tail, a);
    }
    cout<<getMiddle(head)<<"\n";
    return 0;
}
