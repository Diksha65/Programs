#include<iostream>
using namespace std;

struct node{
    node* next;
    node *prev;
    int info;
};

class linkedlist{

    node *head, *tail;

    public:
    linkedlist(){
        head = NULL;
        tail = NULL;
    }

    void display();
    void insertBeginning(int n);
    void insertEnd(int n);
    void insertParticularPos(int n, int pos);
    void insert(int n);
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

void linkedlist::insertBeginning(int n){
    node *temp = new node;
    temp->info = n;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
}

void linkedlist::insertEnd(int n){
    node *temp = new node;
    temp->info = n;
    temp->next = NULL;
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
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

void linkedlist::insert(int n){
    node *cur = new node;
    node *temp = new node;
    temp->info = n;
    temp->next = NULL;
    int pos = 1;
    if(head == NULL){
        temp->prev = NULL;
        head = temp;
        tail = temp;
    } else if(n < head->info){
        insertBeginning(n); 
    } else {
        cur = head;
        while(cur != NULL){
            pos += 1;
            if(cur->info < n){
                if(cur->next == NULL){
                    insertEnd(n);
                    return;
                } else if(cur->next->info > n){
                    insertParticularPos(n, pos);
                    return;
                }
            }
            cur = cur->next;
        }
    }
}

int main(){
    linkedlist l;
    l.insert(10);
    l.display();
    l.insert(13);
    l.display();
    l.insert(2);
    l.display();
    l.insert(0);
    l.display();
    l.insert(5);
    l.display();
    l.insert(16);    
    l.display();
    l.insert(7);
    l.display();
    l.insert(3);
    l.display();
    l.insert(11);
    l.display();
}