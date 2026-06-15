/*
Stack follows Last In First Out Policy(LIFO)
Stack Implementation using Arrays
time complexity for push, pop, size, top is O(1)
space complexity is O(size)


*/
class StackUsingArray{
    private:
        int top=-1, size = 10;
        int arr[size];
    public:
        void push(int val){
            if(top==size-1){
                cout<<"Stack is Full\n";
                return;
            }
            arr[++top] = val;
            cout<<"Element valued "<<val<<" inserted into stack\n";
        }
        int top(){
            if(top==-1){
                cout<<"Stack is Empty\n";
                return;
            }
            return arr[top];
        }
        void pop(){
            if(top==-1){
                cout<<"Stack is Empty\n";
                return;
            }
            return arr[top--];
        }
        int size(){
            return top+1;
        }
};
