#include<iostream>
using namespace std;

struct node{
    node* next;
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
    void insertStart(int d);
    void insert(int d);
    void insertPosition(int pos, int d);
    void deleteFirst();
    void deleteLast();
    void deletePosition(int pos);
    void sort();
    void search(int value);
    void reverse();
    void findNthToLastElement(int n);
    void deleteParticularValue(int n);
    int getNumber();
};

void linkedlist::display(){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->info<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void linkedlist::insertStart(int d){
    node *temp = new node;
    temp->info = d;
    temp->next = head;
    head = temp;
}

void linkedlist::insert(int d){
    node *temp = new node;
    temp->info = d;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void linkedlist::insertPosition(int pos, int d){
    node *pre = NULL;
    node *curr = head;
    node *temp = new node;
    for(int i=1;i<pos;++i){
        pre = curr;
        curr = curr->next;
    }
    temp->info = d;
    temp->next = curr;
    pre->next = temp;
}

void linkedlist::deleteFirst(){
    cout<<head->info<<" deleted\n";
    head = head->next;
}

void linkedlist::deleteLast(){
    node *pre = NULL;
    node *curr = head;
    while(curr->next != NULL){
        pre = curr;
        curr = curr->next;
    }
    pre->next = NULL;
    tail = pre;
    cout<<curr->info<<" deleted from last position\n";
    delete curr;
}

void linkedlist::deletePosition(int pos){
    node *pre = NULL;
    node *curr = head;
    for(int i=1;i<pos;++i){
        pre = curr;
        curr = curr->next;
    }
    pre->next = curr->next;
    cout<<curr->info<<" deleted from position "<<pos<<"\n";
    delete curr;
}

void linkedlist::sort(){
    node *temp = new node; 
    node *start = head;
    int value;
    if(head == NULL){
        cout<<"The list is empty\n";
        return;
    }

    while(start != NULL){
        for(temp = start->next; temp != NULL; temp = temp->next){
            if(start->info > temp->info){
                value = start->info;
                start->info = temp->info;
                temp->info = value;
            }
        }
        start = start->next;
    }
}

void linkedlist::search(int value){
    node *temp = head;
    int pos = 1;
    while(temp != NULL){
        if(temp->info == value){
            cout<<"Value Found at position: "<<pos<<"\n";
            return;
        } else {
            pos += 1;
            temp = temp->next;
        }
    }
    cout<<"Element not in list\n";
}
/*
void linkedlist::reverse(){
    node *start = head;
    head = NULL;
    while(start != NULL){
        insertStart(start->info);
        start = start->next;
    }
}
*/

//Correct one. Above has too many memory leaks.
void linkedlist::reverse(){
    node *pre = NULL;
    node *cur = head, *next = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head = pre;
}
/*
void linkedlist::findNthToLastElement(int n){
    node *start = head;
    int count = 0;
    while(start != NULL){
        count += 1;
        start = start->next;
    }
    int pos = count - n + 1;
    start = head;
    for(int i = 1; i<pos; ++i){
        start = start->next;
    }
    cout<<n<<" from last element is "<<start->info<<"\n";
}*/

//Asked in interview
void linkedlist::findNthToLastElement(int n){
    node *slow = head;
    node *fast = head;
    for(int i=1; i<n; i++)
        fast = fast->next;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    cout<<n<<" from last element is "<<slow->info<<"\n";
}

void linkedlist::deleteParticularValue(int n){
    node *temp = head;
    node *pre = NULL;
    while(temp != NULL){
        if(temp->info == n)
            break;
        else{
            pre = temp;
            temp = temp->next;
        }
    }
    if(temp == head){ 
        deleteFirst();
        return;
    }
    pre->next = temp->next;
    delete temp;
}

int linkedlist::getNumber(){
    node *temp = head;
    int n = 0, f = 1, val;
    while(temp != NULL){
        val = temp->info;
        n += val*f;
        f *= 10;
        temp = temp->next;
    }
    return n;
}

int main(){
    /*
    linkedlist l1;
    linkedlist l2;
    l1.insert(5);
    l1.insert(6);
    l1.insert(4);
    l1.display();
    l2.insert(3);
    l2.insert(1);
    l2.insert(2);
    l2.display();
    int n1 = l1.getNumber();
    int n2 = l2.getNumber();
    int n3 = n1+n2;
    int d;
    linkedlist l3;
    while(n3 != 0){
        d = n3%10;
        n3 = n3/10;
        l3.insert(d);
    }
    l3.display();
    */
    linkedlist l;
    l.insert(4);
    l.insert(7);
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insertStart(3);
    l.insertPosition(3, 9);
    l.insertPosition(4, 8);
    l.insertStart(0);
    l.display();
    l.deleteFirst();
    l.display();
    l.deleteLast();
    l.display();
    l.deletePosition(3);
    l.display();
    l.sort();
    l.display();
    l.search(8);
    l.reverse();
    cout<<"After reverse\n";
    l.display();
    l.findNthToLastElement(5);
    l.deleteParticularValue(4);
    l.display();
}
