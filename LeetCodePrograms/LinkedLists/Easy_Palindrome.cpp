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
    bool isPalindrome();
    
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

bool LinkedList::isPalindrome() {
    //Using string and getNumber()
    string s = to_string(getNumber());
    int i=0, j=s.size()-1;
    while(i<=j) {
        if(s[i] == s[j]) {
            i++; j--;
        } else {
            return false;
        }
    }
    return true;
    
    //Using stack
    stack<int> st;
    Node *cur = head;
    while(cur!=NULL) {
        st.push(cur->info);
        cur = cur->next;
    }
    
    cur = head;
    while(cur != NULL) {
        if(cur->info == st.top()) {
            st.pop();
            cur = cur->next;
        } else {
            return false;
        }
    }
    return true;
    
    //Using Recusrion
    
}

int main()
{
    LinkedList ll1;
    ll1.insert(1);
    ll1.insert(2);
    ll1.insert(2);
    ll1.insert(1); 
    cout<<"Palindrome: "<<ll1.isPalindrome()<<"\n";
   
    return 0;
}