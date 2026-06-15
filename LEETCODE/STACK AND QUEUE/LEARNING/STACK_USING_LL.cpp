
class Node{
    Node* next;
    int data;
    public:
    Node(int val, Node* next){
        this->next = next;
        data = val;
    }
}

class stackUsingLL{
    Node* top;
    public:
    int top(){
        return top->data;
    }
    void push(int x){
        Node* newNode = new Node(x, top);
        top = newNode;
    }
    int pop(){
        if(top==NULL)  return NULL;
        Node* temp = top;
        top = top->next;
        int value = temp->next;
        delete(temp);
        return value;
    }

};