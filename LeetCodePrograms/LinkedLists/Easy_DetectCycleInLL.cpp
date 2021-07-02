//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/773/

#include <bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;

struct Node {
    int info;
    Node* next;
    Node(int x): info(x), next(NULL) {}
    Node(int x, Node *n): info(x), next(n) {}
};

class LinkedList {
    
    Node *head, *tail;
    
    public:
    LinkedList(Node* h, Node *t) {
        head = h;
        tail = t;
    }
    
    void print(string s);
    
    //Inserting into the list
    void insert(int val);
    bool hasCycle();
};

void LinkedList::print(string s) {
    Node *temp = head;
    
    cout<<s<<": ";
    cout<<temp->info;
    while(temp->next!=NULL) {
        temp = temp->next;
        cout<<"->"<<temp->info;
    }
    cout<<"\n";
    temp = NULL;
}

void LinkedList::insert(int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
        //Empty list
        head = newNode;
        tail = newNode;
    } else {
        //Non-Empty List
        tail->next = newNode;
        tail = newNode;
    }
    newNode = NULL;
    print("insert("+to_string(val)+")");
}

bool LinkedList::hasCycle() {
    Node *slow = head;
    Node *fast = head;

    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next;

        if(slow == fast) return true;
    }
    return false;
}

int main() {

    //1->2->3->4->(cycle)2
    Node* n4 = new Node(4, NULL);
    Node* n3 = new Node(3, n4);
    Node* n2 = new Node(2, n3);
    Node* n1 = new Node(1, n2);
    n4->next = n2;
    LinkedList ll(n1, NULL);
    cout<<"Cycle in LL: "<<ll.hasCycle()<<"\n";

    return 0;
}