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
    void insertStart(int val);
    void insertAt(int val, int pos);
    
    //Deleting from the list
    void deleteFirst();
    void deleteLast();
    void deleteAt(int pos);
    void deleteValue(int val);
    void deleteNodeWithoutAccessToHead(Node *node);
    
    //Searching and Sorting through the list
    void sort();
    void search(int val);
    
    //Reversing the list
    void reverseIteratively();
    Node* reverseRecursivelyFromHead(Node*);
    void reverseUsingStack();
    void reverse();

    //merging sorted list with another sorted list
    Node* mergeWithAnotherSortedListUtil(Node* head1, Node* head2);
    void mergeWithAnotherSortedList(LinkedList ll1);
    
    //Getting some data from the list
    int getNumber();
    
    //Palindrome
    bool isPalindromeUsingNumberInList();
    bool isPalindromeUsingStack();
    bool isPalindromeByReversing();
    void isPalindrome();
    
    //Getting Nth data from the last of the list
    void findNthToLastElementTwoPasses(int n);
    void findNthToLastElementSinglePass(int n);
    void findNthToLastElement(int n);
    void removeNthFromEnd(int n);
    
    //Detect cycle in list
    bool hasCycle();
};

void LinkedList::print(string s) {
    if(head == NULL) {
        cout<<s<<": []\n";
        return;
    }
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

void LinkedList::insertStart(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    if (head == NULL) tail = newNode;
    head = newNode;
    newNode = NULL;
    print("insertStart("+to_string(val)+")");
}

void LinkedList::insertAt(int pos, int val) {
    //pos != index i.e. it does not start from 0
    if(pos == 1) {
        insertStart(val);
        return;
    }
    
    Node *prev = NULL;
    Node *curr = head;
    
    for(int i=1;i<pos;i++) {
        if(curr == NULL) {
            cout<<"pos "<<pos<<" is greater than list size so cannot insert "<<val<<"\n";
            return;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
    if(curr == NULL) {
        insert(val);
        return;
    }
    
    Node *newNode = new Node(val);
    prev->next = newNode;
    newNode->next = curr;
            
    newNode = NULL;
    prev = NULL;
    curr = NULL;
    print("insertAt("+to_string(pos)+","+to_string(val)+")");
}

void LinkedList::deleteFirst() {
    if(head == NULL) {
        cout<<"The list is empty. Cannot delete\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    temp = NULL;
    print("deleteFirst()");
}

void LinkedList::deleteLast() {
    if(tail == NULL) {
        cout<<"The list is empty. Cannot delete";
        return;
    }
    Node* curr = head;
    while(curr->next != tail) {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = NULL;
    tail = curr;
    temp = NULL;
    curr = NULL;
    print("deleteLast()");
}

void LinkedList::deleteAt(int pos) {
    if(pos == 1) {
        deleteFirst();
        return;
    }
    
    Node *prev = NULL;
    Node *curr = head;
    
    for(int i=1;i<pos;i++) {
        prev = curr;
        curr = curr->next;
        
        if(curr == NULL) {
            cout<<"pos "<<pos<<" is greater than list size so cannot delete any value\n";
            return;
        }
    }
    
    Node *temp = curr;
    prev->next = curr->next;
    if(curr->next == NULL) {
        tail = prev;
    }
    temp = NULL;
    curr = NULL;
    prev = NULL;
    print("deleteAt("+to_string(pos)+")");
}

void LinkedList::deleteValue(int val) {
    //Delete the first occurance of this value
    if(head == NULL) {
        cout<<"The list is empty. Cannot delete\n";
        return;
    }
    Node *prev = NULL, *curr = head, *temp = NULL;
    
    while(curr != NULL) {
        if(curr->info == val) {
            if(curr->next == NULL) tail = prev; //last item is being deleted
            if(prev == NULL) {
                head = curr->next; // first item is being deleted
                curr = head;
            } else {
                temp = curr;
                prev->next = curr->next;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    
    temp = NULL;
    curr = NULL;
    prev = NULL;
    print("deleteValue("+to_string(val)+")");
    
}

void LinkedList::deleteNodeWithoutAccessToHead(Node *node) {
    Node *nextNode = node->next;
    int val = node->info;
    node->info = nextNode->info;
    node->next = nextNode->next;
    nextNode=NULL;
    print("deleteNodeWithoutAccessToHead("+to_string(val)+")");
}

void LinkedList::sort() {
    if(head == NULL) {
        cout<<"The list is empty.";
        return;
    }
    
    Node *cur = head;
    
    while(cur != NULL) {
        for(Node* temp = cur->next; temp!=NULL; temp=temp->next) {
            if(cur->info > temp->info) {
                int a = cur->info;
                cur->info = temp->info;
                temp->info = a;
            }
        }
        cur = cur->next;
    }
    print("Sort");
}

void LinkedList::search(int val) {
    Node *temp = head;
    int pos = 1;
    while(temp!=NULL) {
        if(temp->info == val) {
            cout<<val<<" found at pos "<<pos<<"\n";
            return;
        } else {
            pos += 1;
            temp = temp->next;
        }
    }
    cout<<val<<" not found in the list\n";
}

void LinkedList::reverseIteratively() {
    //Iteratively: O(n) time and O(1) space
    Node *prev=NULL, *curr=head, *next=NULL;
    
    while(curr!=NULL) {
        next = curr->next;
        curr->next = prev;
        if(prev == NULL) tail = curr;
        prev = curr;
        curr = next;
    }
    head = prev;
    print("reverseIteratively: ");
}

Node* LinkedList::reverseRecursivelyFromHead(Node* temp) {
    //Recursively using *HEAD: O(n) time and O(1) space
    if(temp == NULL || temp->next == NULL) return temp;
    
    Node* rest = reverseRecursivelyFromHead(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    tail = temp;
    
    head = rest;
    return head;
}

void LinkedList::reverseUsingStack() {
    //Using stack
    stack<Node*> s;
    
    Node* curr = head, *temp = NULL;
    while(curr->next!=NULL) {
        s.push(curr);
        curr = curr->next;
    }
    
    head = curr;
    while(!s.empty()) {
        curr->next = s.top();
        s.pop();
        curr = curr->next;
    }
    tail = curr;
    curr->next = NULL;
    
    print("reverseUsingStack");
}

void LinkedList::reverse() {
    
    //Iteratively
    reverseIteratively();
    
    //Recursively using *HEAD
    Node *n = reverseRecursivelyFromHead(head);
    print("reverseRecursivelyFromHead");
    
    //Recursively using *TAIL
    reverseUsingStack();
}

Node* LinkedList::mergeWithAnotherSortedListUtil(Node* h1, Node* h2) {
    //Assuming h1 data < h2 data
    
    //Recursively
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    
    if(h1->info < h2->info) {
        h1->next = mergeWithAnotherSortedListUtil(h1->next, h2);
        return h1;
    } else {
        h2->next = mergeWithAnotherSortedListUtil(h1, h2->next);
        return h2;
    }
    
    //Iteratively
    if(h1->next == NULL) {
        h1->next = h2;
        return h1;
    }
    
    Node *cur1 = h1, *n1 = h1->next;
    Node *cur2 = h2, *n2 = h2->next;
    
    while(n1 != NULL && cur2 != NULL) {
        //If cur1 < cur2 < n1 then do: cur1->cur2->n1
        if(cur2->info >= cur1->info && cur2->info <= n1->info) {
            n2 = cur2->next;
            cur2->next = n1;
            cur1->next = cur2;
            
            //move cur1 and cur2 to the next pointers
            cur1 = cur2;
            cur2 = n2;
        } else {
            cur1 = cur1->next;
            n1 = n1->next;
        }
    }
    if(cur2 != NULL) cur1->next = cur2;
    return h1;
}

void LinkedList::mergeWithAnotherSortedList(LinkedList ll1) {
    Node *temp;
    if(head->info <= ll1.head->info) {
        temp = mergeWithAnotherSortedListUtil(head, ll1.head);
    } else {
        temp = mergeWithAnotherSortedListUtil(ll1.head, head);
    }
    
    //printing
    cout<<"mergeWithAnotherSortedList: ";
    cout<<temp->info;
    while(temp->next!=NULL) {
        temp = temp->next;
        cout<<"->"<<temp->info;
    }
    cout<<"\n";
    temp = NULL;
    
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

bool LinkedList::isPalindromeUsingNumberInList() {
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
}

bool LinkedList::isPalindromeUsingStack() {
    //Using stackL O(n) time O(n) space
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
}

bool compare(Node *a, Node *b) {
    if(a == NULL & b == NULL) return true;
    return a && b && (a->info == b->info) && compare(a->next, b->next);
}

Node* getMiddleElement(Node *head, bool &odd) {
    Node *prev=NULL, *slow=head, *fast = head;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != NULL) {
        //Its odd
        odd = true;
    }

    //This is done specifically for this case where we want to compare 2 halves of a list
    prev->next = NULL;

    return odd ? slow->next : slow;
}

Node* reverseFromNode(Node *head) {
    Node *prev = NULL, *curr=head, *next=NULL;

    while(curr!=NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool LinkedList::isPalindromeByReversing() {
    //By reversing
    bool odd = false;
    Node *mid = getMiddleElement(head, odd);

    Node *reverseListHead = reverseFromNode(mid);

    return compare(head, reverseListHead);
}

void LinkedList::isPalindrome() {
    //Using string and getNumber()
    cout<<"Checking palindrome using number in list: "<<isPalindromeUsingNumberInList()<<"\n";

    //Using stack
    cout<<"Checking palindrome using stack: "<<isPalindromeUsingStack()<<"\n";

    //By reversing
    cout<<"Checking palindrome by reversing: "<<isPalindromeByReversing()<<"\n";
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
    int pos = size-n+1;
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

void LinkedList::removeNthFromEnd(int n) {
    if(head == NULL) {
        cout<<"The list is empty\n";
        return;
    }
    
    Node *prev=NULL, *slow=head, *fast=head;
    
    for(int i=1;i<n;i++) {
        fast=fast->next;    
        if(fast==NULL) {
            cout<<n<<" is greater than the size of the list\n";
            return;
        }
    }
    
    while(fast->next!=NULL) {
        prev=slow;
        slow=slow->next;
        fast=fast->next;
    }
    
    if(prev == NULL) {
        //Only element
        head = slow->next;
    } else {
        prev->next = slow->next;
    }
    slow=NULL;
    fast=NULL;
    print("removeNthFromEnd("+to_string(n)+")");
}

void LinkedList::findNthToLastElement(int n) {
    //Using 2 passes
    cout<<"2 passes ---\n";
    findNthToLastElementTwoPasses(n);

    //Using 1 pass
    cout<<"1 pass ---\n";
    findNthToLastElementSinglePass(n);
}

bool LinkedList::hasCycle() {
    Node *slow = head;
    Node *fast = head;

    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next;

        if(slow == fast) return true;
    }
    return false;
}

int main() {
    //Can see the test cases from the individual files (check the same folder where this was found)
    return 0;
}