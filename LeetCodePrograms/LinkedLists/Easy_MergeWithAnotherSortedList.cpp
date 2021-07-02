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

    //Getting some data from the list
    Node* mergeWithAnotherSortedListUtil(Node* head1, Node* head2);
    void mergeWithAnotherSortedList(LinkedList ll1);
    
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

//Assuming h1 data < h2 data
Node* LinkedList::mergeWithAnotherSortedListUtil(Node* h1, Node* h2) {
    
    //Recursively
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    
    if(h1->info < h2->info) {
        h1->next = mergeWithAnotherSortedListUtil(h1->next, h2);
        return h1;
    } else {
        h2->next = mergeWithAnotherSortedListUtil(h1, h2->next);
        return h2;
    }
    
    //Iteratively
    if(h1->next == NULL) {
        h1->next = h2;
        return h1;
    }
    
    Node *cur1 = h1, *n1 = h1->next;
    Node *cur2 = h2, *n2 = h2->next;
    
    while(n1 != NULL && cur2 != NULL) {
        //If cur1 < cur2 < n1 then do: cur1->cur2->n1
        if(cur2->info >= cur1->info && cur2->info <= n1->info) {
            n2 = cur2->next;
            cur2->next = n1;
            cur1->next = cur2;
            
            //move cur1 and cur2 to the next pointers
            cur1 = cur2;
            cur2 = n2;
        } else {
            cur1 = cur1->next;
            n1 = n1->next;
        }
    }
    if(cur2 != NULL) cur1->next = cur2;
    return h1;
}

void LinkedList::mergeWithAnotherSortedList(LinkedList ll1) {
    Node *temp;
    if(head->info <= ll1.head->info) {
        temp = mergeWithAnotherSortedListUtil(head, ll1.head);
    } else {
        temp = mergeWithAnotherSortedListUtil(ll1.head, head);
    }
    
    cout<<"mergeWithAnotherSortedList: ";
    cout<<temp->info;
    while(temp->next!=NULL) {
        temp = temp->next;
        cout<<"->"<<temp->info;
    }
    cout<<"\n";
    temp = NULL;
    
}

int main()
{
    LinkedList ll1;
    ll1.insert(1);
    ll1.insert(2);
    ll1.insert(3);
    ll1.insert(4); 

    LinkedList ll2;
    ll2.insert(1);
    ll2.insert(2);
    ll2.insert(3);
    ll2.insert(4);
    
    ll1.mergeWithAnotherSortedList(ll2);
    return 0;
}