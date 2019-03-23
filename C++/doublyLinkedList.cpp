#include<iostream>
using namespace std;

struct node{
    node* next;
    node* prev;
    int info;
};

class linkedlist{
    
    node *head;
    node *tail;

    public:
    linkedlist(){
        head = NULL;
        tail = NULL;
    }

    void display();
    void insert(int n);
    void insertBeginning(int n);
    void insertParticularPos(int n, int pos);
    void deleteFirst();
    void deleteLast();
    void deletePosition(int pos);
    void deleteValue(int val);
    void reverse();
    void sort();
};

void linkedlist::display(){
    node *temp = new node;
    temp = head;
    while(temp != NULL){
        cout<<temp->info<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void linkedlist::insert(int n){
    node *temp = new node;
    node *start = new node;
    temp->info = n;
    temp->next = NULL;
    if(head == NULL){
        temp->prev = NULL;
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void linkedlist::insertBeginning(int n){
    node *temp = new node;
    temp->info = n;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
}

void linkedlist::insertParticularPos(int n, int pos){
    node *temp = new node;
    node *pre = new node;
    node *cur = new node;
    cur = head;
    for(int i=1;i<pos;++i){
        pre = cur;
        cur = cur->next;
    }
    temp->info = n;
    temp->next = cur;
    temp->prev = pre;
    cur->prev = temp;
    pre->next = temp;
}

void linkedlist::deleteFirst(){
    node *temp = new node;
    temp = head;
    head->next->prev = NULL;
    cout<<head->info<<" deleted\n";
    head = head->next;    
}

void linkedlist::deleteLast(){
    node *cur = new node;
    node *pre = new node;
    cur = head;
    while(cur->next != NULL){
        pre = cur;
        cur = cur->next;
    }
    pre->next = NULL;
    cout<<tail->info<<" deleted\n";
    tail = pre;
    delete cur;
}

void linkedlist::deletePosition(int pos){
    node *pre = new node;
    node *cur = new node;
    cur = head;
    for(int i=1;i<pos;++i){
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    cur->next->prev = cur->prev;
    cout<<cur->info<<" deleted\n";
    delete cur;
}

void linkedlist::deleteValue(int value){
    node *pre = new node;
    node *cur = new node;
    pre = NULL;
    cur = head;
    while(cur != NULL && cur->info != value){
        pre = cur;
        cur = cur->next;
    }
    if(cur == head){
        deleteFirst();
        return;
    }
    pre->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
}

void linkedlist::reverse(){
    node *temp = new node;
    temp = tail;
    while(temp != NULL){
        cout<<temp->info<<" ";
        temp = temp->prev;
    }
    cout<<"\n";
}

void linkedlist::sort(){
    node *start = new node;
    node *temp = new node;
    start = head;
    int value;
    while(start != NULL){
        for(temp = start->next; temp != NULL; temp = temp->next){
            if(start->info < temp->info){
                value = start->info;
                start->info = temp->info;
                temp->info = value;
            }
        }
        start = start->next;
    }
}

int main(){
    linkedlist l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insertBeginning(5);
    l.display();
    l.insertParticularPos(6, 5);
    l.display();
    l.deleteFirst();
    l.display();
    l.deletePosition(3);
    l.display();
    l.deleteValue(6);
    l.display();
    l.reverse();
    l.insert(9);
    l.insert(7);
    l.insert(3);
    l.insert(10);
    l.sort();
    l.reverse();
}