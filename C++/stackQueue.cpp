#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Queue {
    public:
    stack<int> s1, s2;
    void enqueue(int x);
    void dequeue();
};

void Queue::enqueue(int x){
    s1.push(x);
}

void Queue::dequeue(){
    int x;
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    x = s2.top();
    s2.pop();
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    cout<<x<<"\n";
}

void sort(stack<int> s){
    cout<<s.peek();
}

int main(){
    Queue q;
    //q.enqueue(1);
    //q.enqueue(2);
    //q.enqueue(3);
    //q.enqueue(4);
    //q.dequeue();
    stack<int> s;
    s.push(8);
    s.push(3);
    s.push(0);
    s.push(5);
    s.push(6);
    sort(s);
}
/*
struct node{
    node *next;
    int info;
};

struct queue{
    node *stack1;
    node *stack2;
};

void push(node *top, int val);
void pop(node *top);
void enqueue(queue *last, int val);
int dequeue(queue *first);

void enqueue(queue *last, int val){
    push(q->stack1, val);
}

int dequeue(queue *first){
    int x;
    if(first->stack1 == NULL && first->stack2 == NULL){
        cout<<"Queue is empty\n";
        return;
    }
    if(first->stack2 == NULL){
        while(first->stack1 != NULL){
            x = pop(first->stack1);

        }
    }
}
*/

/*
class Stack{
    node *top;
    
    node pop(){
        if(top != NULL){
            int v = top->info;
            top = top->next;
            return v;
        }
        return null;
    }

    void push(int v){
        node *temp = new node;
        temp->info = temp;
        temp->next = top;
        top = temp;
    }
};


class Queue{
    node *first, *last;

    void enqueue(int v){
        if(!first){
            last = new node;
            last->info = v;
            last->next = NULL;
            first = last;
        } else {
            node *temp = new node;
            temp->info = v;
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
    }

    node dequeue(){
        if(front != NULL){
            int v = front->data;
            front = front->next;
            return v;
        }
        return NULL;
    }
};
*/