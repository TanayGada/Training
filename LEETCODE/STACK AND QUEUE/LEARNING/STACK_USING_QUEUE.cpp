/*
Stack using Queue

while pushing the element into Queue, we make sure to pop all elements before newElement and push them ahead of newlyAddedElement

push(1)
q1 => 1
push(2)
q1 => 1 2 => 2 1
push(3)
q1 => 2 1 3 => 3 2 1
*/

class MyStack {
public:
    queue<int> q1;
    MyStack() {
    }
    
    void push(int x){
        q1.push(x);
        int size = q1.size();
        for(int i=0;i<size-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop(){
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    int top(){
        int topElement = q1.front();
        return topElement;
    }
    bool empty() {
        return q1.empty();
    }
};
