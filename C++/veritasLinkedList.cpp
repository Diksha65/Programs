#include<iostream>
#include<vector>
using namespace std;

struct node {
    int data;
    node *next;

    bool operator==(node *other){
        return (other->data == data && other->next == next);
    }
};

class LinkedList{
    node *head, *tail;

    public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    int search(int x);
    void insertStart(int x);
    void insertEnd(int x);
    void insertParticularLoc(int x, int pos);
    void deleteStart();
    void deleteEnd();
    void deleteParticularLoc(int pos);
    void deleteParticularValue(int x);
    void deleteNodesGreaterThan(int x);
    void findLoop();
    void findLoopLength();
    void print();
};

int LinkedList::search(int x){
    node *temp = new node();
    temp = head;
    int pos = 1;
    while(temp->next != NULL){
        if(temp->data == x){
            return pos;
        } else {
            pos += 1;
            temp = temp->next;
        }
    }
    return -1;
}

void LinkedList::insertStart(int x){
    node *temp = new node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void LinkedList::insertEnd(int x){
    node *root = new node();
    node *temp = new node();
    root = head;
    if(head == NULL)
        insertStart(x);
    else {
        while(root->next != NULL){
            root = root->next;
        }
        temp->data = x;
        temp->next = NULL;
        root->next = temp;
    }
}

void LinkedList::insertParticularLoc(int x, int pos){
    node *cur = new node();
    node *pre = new node();
    node *temp = new node();
    pre = NULL;
    cur = head;
    if(pos == 1)
        insertStart(x);
    else{
        for(int i=1; i<pos; i++){
            pre = cur;
            cur = cur->next;
        }
        temp->data = x;
        temp->next = cur;
        pre->next = temp;
    }
}

void LinkedList::deleteStart(){
    cout<<head->data<<" deleted\n";
    head = head->next;
}

void LinkedList::deleteEnd(){
    node *pre = new node();
    node *cur = new node();
    cur = head;
    while(cur->next != NULL){
        pre = cur;
        cur = cur->next;
    }
    cout<<cur->data<<" deleted\n";
    pre->next = NULL;
    delete cur;
}

void LinkedList::deleteParticularLoc(int pos){
    node *pre = new node();
    node *cur = new node();
    cur = head;
    if(pos == 1)
        deleteStart();
    else{
        for(int i=1;i<pos;i++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        cout<<cur->data<<" deleted from position "<<pos<<"\n";
        delete cur;
    }
}

void LinkedList::deleteParticularValue(int x){
    node *pre = new node();
    node *cur = new node();
    cur = head;
    pre = NULL;
    while(cur->data != x){
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    cout<<cur->data<<" deleted\n";
    delete(cur);
}

void LinkedList::deleteNodesGreaterThan(int x){
    node *temp = new node();
    temp = head;
    while(temp != NULL){
        if(temp->data > x)
            deleteParticularValue(temp->data);
        temp = temp->next;
    }
}

void LinkedList::findLoop(){
    node *slow = new node();
    node *fast = new node();
    slow = head;
    fast = head;
    while(slow->next != NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout<<"Loop present\n";
            cout<<findLoopLength()<<"\n";
            return;
        }
    }
    cout<<"Loop absent\n";
}

int LinkedList::findLoopLength(){
    node *slow = head;
    node *fast = head;
    int count = 0;
    bool counter = false;
    while(fast->next != NULL && slow->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            if(count == 0)
                counter = true;
            else 
                return counter;
        if(counter)
            count += 1;
    }
}

void LinkedList::print(){
    node *temp = new node();
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main(){
    LinkedList l;
    l.insertStart(1);
    l.insertStart(2);
    l.insertEnd(4);
    l.insertEnd(5);
    l.insertEnd(6);
    l.insertParticularLoc(3,1);
    //l.deleteStart();
    //l.deleteEnd();
    //l.deleteParticularLoc(1);
    //l.deleteParticularValue(5);
    //l.insertStart(0);
    l.deleteNodesGreaterThan(3);
    l.print();
    l.findLoop();
}