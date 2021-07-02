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
    
    //Deleting from the list
    void deleteFirst();
    void deleteLast();
    void deleteAt(int pos);
    void deleteValue(int val);
    void deleteNodeWithoutAccessToHead(Node *node);
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

void LinkedList::deleteFirst() {
    if(head == NULL) {
        cout<<"The list is empty. Cannot delete\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    temp = NULL;
    print("deleteFirst()");
}

void LinkedList::deleteLast() {
    if(tail == NULL) {
        cout<<"The list is empty. Cannot delete";
        return;
    }
    Node* curr = head;
    while(curr->next != tail) {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = NULL;
    tail = curr;
    temp = NULL;
    curr = NULL;
    print("deleteLast()");
}

void LinkedList::deleteAt(int pos) {
    if(pos == 1) {
        deleteFirst();
        return;
    }
    
    Node *prev = NULL;
    Node *curr = head;
    
    for(int i=1;i<pos;i++) {
        prev = curr;
        curr = curr->next;
        
        if(curr == NULL) {
            cout<<"pos "<<pos<<" is greater than list size so cannot delete any value\n";
            return;
        }
    }
    
    Node *temp = curr;
    prev->next = curr->next;
    if(curr->next == NULL) {
        tail = prev;
    }
    temp = NULL;
    curr = NULL;
    prev = NULL;
    print("deleteAt("+to_string(pos)+")");
}

void LinkedList::deleteValue(int val) {
    //Delete the first occurance of this value
    if(head == NULL) {
        cout<<"The list is empty. Cannot delete\n";
        return;
    }
    Node *prev = NULL, *curr = head, *temp = NULL;
    
    while(curr != NULL) {
        if(curr->info == val) {
            if(curr->next == NULL) tail = prev; //last item is being deleted
            if(prev == NULL) {
                head = curr->next; // first item is being deleted
                curr = head;
            } else {
                temp = curr;
                prev->next = curr->next;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    
    temp = NULL;
    curr = NULL;
    prev = NULL;
    print("deleteValue("+to_string(val)+")");
    
}

void LinkedList::deleteNodeWithoutAccessToHead(Node *node) {
    Node *nextNode = node->next;
    int val = node->info;
    node->info = nextNode->info;
    node->next = nextNode->next;
    nextNode=NULL;
    print("deleteNodeWithoutAccessToHead("+to_string(val)+")");
}

int main()
{
    LinkedList ll;
    ll.deleteFirst();
    ll.insertAt(1, 4);
    ll.insert(1);
    ll.insert(3);
    ll.insert(4);
    ll.insertStart(5);
    ll.insertAt(4, 6);
    ll.insertAt(1, 0);
    ll.insertAt(8, 0);
    ll.insertAt(10, 0);
    ll.deleteFirst();
    ll.deleteLast();
    ll.insertAt(7, 6);
    ll.deleteAt(1);
    ll.deleteAt(10);
    ll.deleteAt(6);
    ll.insertAt(6,0);
    ll.deleteValue(4);
    ll.insertStart(4);
    ll.insertStart(5);
    ll.insert(6);
    return 0;
}