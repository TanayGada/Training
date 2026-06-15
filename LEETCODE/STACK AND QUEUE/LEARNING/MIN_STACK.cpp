/*
Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

//approach 1 (brute force)
// we are storing element and minElement in stack so sc=>O(2*n), tc=>O(1)


// Always code the solution using Arrays and then use LinkedList Solution showing its advantages
// Dynamic Size, Memory Utilization, No need for relocation, 
class MinStack {
    stack<pair<long long,long long>> s;
public:
    MinStack() {}
    
    void push(int val) {
        long long val1 = (long long )val;
        if(s.empty())   s.push({val1, val1});
        else
        s.push({val1,min(s.top().second,val1)});
    }
    
    void pop() {
        if(s.empty())   return;
        s.pop();
    }
    
    long long top() {
        if(s.empty())   return -1;
        return s.top().first;
    }
    
    long long getMin() {
        if(s.empty())   return -1;
        return s.top().second;
    }
};

//Approach 2 (optimal) sc=>O(n) tc=>O(1)
//https://www.youtube.com/watch?v=NdDIaH91P0g

// Using Linked List
class Node{
    public:
    Node* next;
    int val, minEle;
    
    Node(int val, int minEle, Node* next){
        this->next = next;
        this->val = val;
        this->minEle = minEle;
    }
};

class MinStack {
    Node* head;
public:
    MinStack() {
        head=NULL;
    }
    
    void push(int val) {
        int minElement =val;
        if(head!=NULL)   minElement = head->minEle;
        Node* newNode = new Node(val, min(val,minElement), head);
        newNode->next = head;
        head = newNode;
    }
    
    void pop() {
        if(head==NULL)  return;
        Node* temp = head;
        head = head->next;
        delete(temp);
    }
    
    long long top() {
        return head->val;
    }
    
    long long getMin() {
        return head->minEle;
    }
};