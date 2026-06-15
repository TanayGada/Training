/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* newNode = new QueueNode(x);
        if(rear==NULL){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code       
        if(front==NULL) return -1;
        int value = front->data;
        QueueNode* temp = front;
        front = front->next;
        if(front==NULL){
            rear =NULL;
        }
        delete(temp);
        return value;
}