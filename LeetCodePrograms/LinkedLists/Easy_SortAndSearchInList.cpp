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
    void sort();
    void search(int val);  
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

void LinkedList::sort() {
    if(head == NULL) {
        cout<<"The list is empty.";
        return;
    }
    
    Node *cur = head;
    
    while(cur != NULL) {
        for(Node* temp = cur->next; temp!=NULL; temp=temp->next) {
            if(cur->info > temp->info) {
                int a = cur->info;
                cur->info = temp->info;
                temp->info = a;
            }
        }
        cur = cur->next;
    }
    print("Sort");
}

void LinkedList::search(int val) {
    Node *temp = head;
    int pos = 1;
    while(temp!=NULL) {
        if(temp->info == val) {
            cout<<val<<" found at pos "<<pos<<"\n";
            return;
        } else {
            pos += 1;
            temp = temp->next;
        }
    }
    cout<<val<<" not found in the list\n";
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
    ll.sort();
    ll.search(5);
    return 0;
}