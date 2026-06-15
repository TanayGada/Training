/*

time complexity for push, pop, top is O(1);
limitation here is that front and rear are both forward moving pointers and hence even when we pop elements out from queue the size of array increases but size of queue decreases
*/

class QueueUsingArrays{
    private:
    int front=0, back=0, size=10;
    int arr[size];

    public:
    void push(int x){
        if(back==size-1){
            cout<<"Queue is Full\n";
            return;
        }
        arr[back++] = x;
    }
    int top(){
        if(front<back){
            return arr[front];
        }
        return -1;
    }
    void pop(){
        if(front<back){
            front++;
        }
    }
};