#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MyStack {
    stack<int> s;
    stack<int> min;

    public:
    MyStack() {
        
    }

    void push(int ele) {
        if(minEmpty())
            min.push(ele);
        else if(ele < min.top())
            min.push(ele);
        s.push(ele);
    }

    int top() {
        if(stackEmpty()) 
            return -1;
        return s.top();
    }

    void pop() {
        if(stackEmpty()) 
            return;
        if(min.top() == s.top())
            min.pop();
        s.pop();
    }

    int size() {
        return s.size();
    }

    int minimum() {
        return min.top();
    }

    bool stackEmpty() {
        return s.size() == 0;
    }

    bool minEmpty() {
        return min.size() == 0;
    }
};

int main() {
    cout<<"Enter the elements you want to push\n";
    MyStack s;
    int i=1, n;
    while(i++<=10) {
        cin>>n;
        s.push(n);
        cout<<"Min: "<<s.minimum()<<"\n";
    }
    s.pop();
    cout<<"Min: "<<s.minimum()<<"\n";
    s.pop();
    cout<<"Min: "<<s.minimum()<<"\n";
    s.pop();
    cout<<"Min: "<<s.minimum()<<"\n";
    s.pop();
    cout<<"Min: "<<s.minimum()<<"\n";
}