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
    
    //Getting some data from the list
    int getNumber();
    
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

int LinkedList::getNumber() {
    Node *temp = head;
    int n=0;
    while(temp != NULL) {
        n = n*10 + temp->info;
        temp = temp->next;
    }
    return n;
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
    cout<<"Number: "<<ll.getNumber()<<"\n";
    return 0;
}