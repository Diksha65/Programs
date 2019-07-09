#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class linkedList {
    Node *head, *tail;
    
    public:
    linkedList() {
        head = NULL;
        tail = NULL;
    }

    void addNode(int n) {
        Node *temp = new Node;
        temp->data = n;
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail -> next = temp;
            tail = tail->next;
        }
    }

    Node* getHead() {
        return head;
    }

    static void display(Node *head) {
        if(head == NULL) {
            cout<<"\n";
        } else {
            cout<<head->data<<" ";
            display(head->next);
        }
    }

    void removeDuplicatesWithBuffer();
    void removeDuplicatesWithoutBuffer();
    
    void kthToLastElement(int k);
    void kthToLastElementUsingTwoPointers(int k);

    void removeMiddleElement();
    void removeParticularNode(Node *node);

    void partitionAroundValue(int k);

    void sumOfDigitsReverseOrder(Node *head2);
    void sumOfDigitsForwardOrder(Node *head2);

    void palindrome();

    void intersectionON2(Node *head2);
    void intersectionOMplusN(Node *head2);

    void cycleDetection();
};

bool isPresent(int d, vector<int> v) {
    for(int i=0;i<v.size();i++) {
        if(v[i] == d)
            return true;
    }
    return false;
}

void linkedList::removeDuplicatesWithBuffer() {
    Node *temp = head;
    vector<int> v;
    v.push_back(temp->data);
    while(temp->next != NULL) {
        if(isPresent(temp->next->data, v)) {
            //delete the node
            temp->next = temp->next->next;
            
        } else {
            //insert the node into the vector
            v.push_back(temp->next->data);
            temp = temp->next;
        }
    }
}

void linkedList::removeDuplicatesWithoutBuffer() {
    Node *slow = head, *fast = head;
    while(slow != NULL) {    
        while(fast->next != NULL) {
            if(fast->next->data == slow->data) {
                fast->next = fast->next->next;
            } else {
                fast = fast->next;
            }
        }
        slow = slow->next;
        fast = slow;
    }
}

void linkedList::kthToLastElement(int k) {
    int size = 0;
    Node *temp = head;
    while(temp != NULL) {
        size += 1;
        temp = temp->next;
    }
    temp = head;
    for(int i=1;i<size-k+1;i++) {
        temp = temp->next;
    }
    cout<<temp->data;
}

void linkedList::kthToLastElementUsingTwoPointers(int k) {
    Node *slow = head, *fast = head;
    for(int i=1;i<k;i++) {
        fast = fast->next;
    }
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    cout<<slow->data;
}

void linkedList::removeMiddleElement() {
    Node *slow = head, *fast = head, *temp = NULL;
    while(fast->next != NULL) {
        if(fast->next->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        } else {
            break;
        }
    }
    if(temp != NULL) {
        temp->next = slow->next;
    }
}

void linkedList::removeParticularNode(Node *node) {
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

void linkedList::partitionAroundValue(int k) {
    Node *slow= head, *fast = head;
    while(fast != NULL) {
        if(fast->data < k && slow->data < k) {
            slow = slow->next;
            fast = fast->next;
        } else if(fast->data >= k && slow->data >= k) {
            fast = fast->next;
        } else if(fast->data < k && slow->data >= k) {
            swap(slow->data, fast->data);
            slow = slow->next;
            fast = fast->next;
        } else {
            slow = slow->next;
            fast = fast->next;
        }
    }
}

void linkedList::sumOfDigitsReverseOrder(Node *head2) {
    Node *temp1 = head, *temp2 = head2;
    linkedList sumL;
    int sum = 0, carry = 0, rem;
    while(temp1 != NULL && temp2 != NULL) {
        sum = temp1->data + temp2->data + carry;
        carry = sum/10;
        rem = sum%10;
        sumL.addNode(rem);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(carry != 0) {
        sumL.addNode(carry);
    }
    while(temp1!=NULL) {
        sum = temp1->data  + carry;
        carry = sum/10;
        rem = sum%10;
        sumL.addNode(rem);
        temp1 = temp1->next;
    }
    while(temp2!=NULL) {
        sum = temp2->data  + carry;
        carry = sum/10;
        rem = sum%10;
        sumL.addNode(rem);
        temp2 = temp2->next;
    }
    sumL.display(sumL.getHead());
}

void linkedList::sumOfDigitsForwardOrder(Node *head2) {
    Node *temp1 = head, *temp2 = head2;
    stack<int> s1, s2, s3;
    linkedList sumL;
    while(temp1 != NULL) {
        s1.push(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL) {
        s2.push(temp2->data);
        temp2 = temp2->next;
    }
    int sum = 0, carry = 0, rem = 0;
    while(!s1.empty() && !s2.empty()) {
        sum = s1.top() + s2.top() + carry;
        carry = sum/10;
        rem = sum%10;
        s3.push(rem);
        s1.pop();
        s2.pop();
    }
    while(!s1.empty()) {
        sum = s1.top() + carry;
        carry = sum/10;
        rem = sum%10;
        s3.push(rem);
        s1.pop();
    }
    while(!s2.empty()) {
        sum = s2.top() + carry;
        carry = sum/10;
        rem = sum%10;
        s3.push(rem);
        s2.pop();
    }
    if(carry != 0) {
        s3.push(carry);
    }
    while(!s3.empty()) {
        sumL.addNode(s3.top());
        s3.pop();
    }
    sumL.display(sumL.getHead());
}

void linkedList::palindrome() {
    Node *mid = head, *fast=head;
    stack<int> s;
    while(fast->next!=NULL) {
        s.push(mid->data);
        if(fast->next->next != NULL) {
            mid = mid->next;
            fast=fast->next->next;
        } else {
            break;
        }
    }
    mid = mid->next;
    while(mid!=NULL) {
        if(s.top() == mid->data) {
            s.pop();
            mid = mid->next;
        } else {
            cout<<"Not palindrome\n";
            return;
        }
    }
    cout<<"Palindrome\n";
}

void linkedList::intersectionON2(Node *head2) {
    Node *temp1 = head, *temp2 = head2;
    while(temp2 != NULL) {
        temp1 = head;
        while(temp1 != NULL) {
            if(temp1->data == temp2->data) {
                cout<<temp2->data;
                return;
            } else {
                temp1 = temp1 -> next;
            }
        }
        temp2 = temp2->next;
    }
}

void linkedList::intersectionOMplusN(Node *head2) {
    Node *temp1 = head, *temp2 = head2;
    int size1= 0, size2 = 0;
    while(temp1!=NULL) {
        size1++;
        temp1 = temp1->next;
    }
    while(temp2!=NULL) {
        size2++;
        temp2 = temp2->next;
    }
    
    int diff, i=1;
    temp1 = head; temp2 = head2;
    
    if(size1>size2) {
        diff = size1 - size2;
        while(i++ <= diff) {
            temp1 = temp1->next;
        }
    } else {
        diff = size2 - size1;
        while(i++ <= diff) {
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL) {
        if(temp1->data == temp2->data) {
            cout<<temp2->data<<"\n";
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

void linkedList::cycleDetection() {
    tail->next = head;
    Node *slow = head, *fast = head;
    while(slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        
    }   
}

int main() {

    linkedList n1, n2;
    int i = 1, n;
    cout<<"Enter 1st number:\n";
    while(i++<=6) {
        cin>>n;
        n1.addNode(n);
    }
    //i=1;
    //cout<<"Enter 2nd number:\n";
    //while(i++<=3) {
    //    cin>>n;
    //    n2.addNode(n);
    //}
    //l.removeDuplicatesWithBuffer();
    //l.removeDuplicatesWithoutBuffer();
    //l.kthToLastElement(5);
    //l.kthToLastElementUsingTwoPointers(4);
    //l.removeMiddleElement();
    //l.removeParticularNode(l.getHead()->next->next);
    //l.partitionAroundValue(3);
    //n1.sumOfDigitsReverseOrder(n2.getHead());
    //n1.sumOfDigitsForwardOrder(n2.getHead());
    //n1.palindrome();
    //n1.intersectionON2(n2.getHead());
    //n1.intersectionOMplusN(n2.getHead());
    //n1.cycleDetection();
    cout<<"\nDisplay:\n";
    n1.display(n1.getHead());
}
