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
    void insertStart(int val);
    void insertAt(int val, int pos);
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

void LinkedList::insertStart(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    if (head == NULL) tail = newNode;
    head = newNode;
    newNode = NULL;
    print("insertStart("+to_string(val)+")");
}

void LinkedList::insertAt(int pos, int val) {
    //pos != index i.e. it does not start from 0
    if(pos == 1) {
        insertStart(val);
        return;
    }
    
    Node *prev = NULL;
    Node *curr = head;
    
    for(int i=1;i<pos;i++) {
        if(curr == NULL) {
            cout<<"pos "<<pos<<" is greater than list size so cannot insert "<<val<<"\n";
            return;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
    if(curr == NULL) {
        insert(val);
        return;
    }
    
    Node *newNode = new Node(val);
    prev->next = newNode;
    newNode->next = curr;
            
    newNode = NULL;
    prev = NULL;
    curr = NULL;
    print("insertAt("+to_string(pos)+","+to_string(val)+")");
}

int main()
{
    LinkedList ll;
    ll.insertAt(1, 4);
    ll.insert(1);
    ll.insert(3);
    ll.insert(4);
    ll.insertStart(5);
    ll.insertAt(4, 6);
    ll.insertAt(1, 0);
    ll.insertAt(8, 0);
    ll.insertAt(10, 0);
    ll.insertAt(7, 6);
    ll.insertAt(6,0);
    return 0;
}