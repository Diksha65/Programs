/*
    Implementing a stack where we can get minimum element in O(1) time and O(1) extra space without using any array or list.
    New variable 'minEle' stores the current minimum of the stack.
    To push a new element 'X' - (X < min) ? (push '2X-min' & min = x): (push 'X' & min = min)
    To pop a top element 'Y' - (Y < min) ? (original element = min & min = 2*min-Y) : (original element = Y & min = min)
*/

#include<iostream>
#include<stack>
using namespace std;

class _stack {
    stack<int> s;
    int minEle;
    public:
        int getMin();
        int pop();
        void push(int x);
};

void _stack::push(int x) {
    if(s.empty()) {
        minEle = x;
        s.push(x);
    } else {
        if(x >= minEle) 
            s.push(x);
        else {
            s.push(2*x-minEle);
            minEle = x; 
        }
    }
}

int _stack::getMin() {
    if(s.empty()) 
        return -1;
    else 
        return minEle;
}

int _stack::pop() {
    if(s.empty()) {
        return -1;
    } else {
        int y = s.top();
        s.pop();
        if(y < minEle) {
            int temp = 2*minEle-y;
            y = minEle;
            minEle = temp;
        }
        return y;
    }
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int Q;
        cin>>Q;
        _stack *a = new _stack();
        while(Q--) {
            int qt;
            cin>>qt;
            if(qt == 1) {
                int att;
                cin>>att;
                a->push(att);
            } else if(qt == 2) {
                cout<<a->pop()<<" ";
            } else if(qt == 3) {
                cout<<a->getMin()<<" ";
            }
        }
        cout<<"\n";
    }
}