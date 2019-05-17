#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(struct Node** head, struct Node** tail, int a) {
    struct Node *n = new Node;
    n->data = a;
    n->next = NULL;
    if(*head == NULL) 
        *head = n;
    else
        (*tail)->next = n;
    *tail = n;
}

int getMiddle(Node* head) {
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


int main() {
    int T, N, a;
    cin>>T;
    while(T--) {
        struct Node *head = NULL, *tail = NULL;
        cin>>N;
        while(N--) {
            cin>>a;
            append(&head, &tail, a);
        }
        cout<<getMiddle(head)<<"\n";
    }
    return 0;
}