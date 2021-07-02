//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/

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
    void findNthToLastElementTwoPasses(int n);
    void findNthToLastElementSinglePass(int n);
    void findNthToLastElement(int n);
    
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

void LinkedList::findNthToLastElementTwoPasses(int n) {
    if(head == NULL) {
        cout<<"The list is empty\n";
        return;
    }
    
    //Using 2 passes
    int size=1;
    Node *curr=head;
    while(curr->next!=NULL) {
        size += 1;
        curr=curr->next;
    }
    if(n > size) {
        cout<<n<<" is greater than the list size\n";
        return;
    }
    int pos = size-n;
    curr = head;
    for(int i=1;i<pos;i++) {
        curr = curr->next;
    }
    cout<<"The element at the distance of "<<n<<" from the end is "<<curr->info<<"\n";
    curr = NULL;
    
}

void LinkedList::findNthToLastElementSinglePass(int n) {
    if(head == NULL) {
        cout<<"The list is empty\n";
        return;
    }
    
    //Using 1 pass (Interviewsss)
    Node *slow = head, *fast = head;
    for(int i=1;i<n;i++) {
        fast = fast->next;
        if(fast == NULL) {
            cout<<n<<" is greater than the list size\n";
            return;
        } 
    }
    
    while(fast->next != NULL) {
        slow = slow->next;
        fast=fast->next;
    }
    cout<<"The element at the distance of "<<n<<" from the end is "<<slow->info<<"\n";
    slow = NULL;
    fast = NULL;
}

void LinkedList::findNthToLastElement(int n) {
    //Using 2 passes
    cout<<"2 passes ---\n";
    findNthToLastElementTwoPasses(n);

    //Using 1 pass
    cout<<"1 pass ---\n";
    findNthToLastElementSinglePass(n);
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
    ll.findNthToLastElement(2);
    ll.findNthToLastElement(4);
    ll.findNthToLastElement(1);
    ll.findNthToLastElement(5);
    ll.findNthToLastElement(6);
    return 0;
}