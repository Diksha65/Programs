//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/

#include <bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;

struct Node {
    int info;
    Node* next;
    Node(int x): info(x), next(NULL) {}
};

class LinkedList {
    
    Node *head, *tail;
    
    public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    void print(string s);
    
    //Inserting into the list
    void insert(int val);

    //Transforming the list
    void reverseIteratively();
    Node* reverseRecursivelyFromHead(Node*);
    void reverseUsingStack();
    void reverse();
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

void LinkedList::reverseIteratively() {
    //Iteratively: O(n) time and O(1) space
    Node *prev=NULL, *curr=head, *next=NULL;
    
    while(curr!=NULL) {
        next = curr->next;
        curr->next = prev;
        if(prev == NULL) tail = curr;
        prev = curr;
        curr = next;
    }
    head = prev;
    print("reverseIteratively: ");
}

Node* LinkedList::reverseRecursivelyFromHead(Node* temp) {
    //Recursively using *HEAD: O(n) time and O(1) space
    if(temp == NULL || temp->next == NULL) return temp;
    
    Node* rest = reverseRecursivelyFromHead(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    tail = temp;
    
    head = rest;
    return head;
}

void LinkedList::reverseUsingStack() {
    //Using stack
    stack<Node*> s;
    
    Node* curr = head, *temp = NULL;
    while(curr->next!=NULL) {
        s.push(curr);
        curr = curr->next;
    }
    
    head = curr;
    while(!s.empty()) {
        curr->next = s.top();
        s.pop();
        curr = curr->next;
    }
    tail = curr;
    curr->next = NULL;
    
    print("reverseUsingStack");
}

void LinkedList::reverse() {
    
    //Iteratively
    reverseIteratively();
    
    //Recursively using *HEAD
    Node *n = reverseRecursivelyFromHead(head);
    print("reverseRecursivelyFromHead");
    
    //Recursively using *TAIL
    reverseUsingStack();
}

int main()
{
    LinkedList ll;
    ll.insert(6);
    ll.insert(1);
    ll.insert(7);
    ll.insert(0);
    ll.insert(5);
    ll.insert(3);
    ll.insert(4);
    ll.insert(6);
    ll.reverse();
    return 0;
}