/*
To Implement Queue using Stack
There are 2 approaches

APPROACH 1 (using 2 stacks)
- push heavy method
1. We always push newElements into s1
2. Whenever we need to push new element
3. We pop and push all elements from s1 to s2
4. We then push newElement into s1 then pop and push all elements from s2 to s1

consider s1 =[1
newElement = 5
s1 = [
s2 = [1

s1 = [5
s2 = [1

s1 = [5,1
s2 = [

we have element 1 as topElement which is also the frontElement of queue
tc => O(2*n), sc => O(2*n)
*/

class queueUsingStack{
    stack<int> s1, s2;

    public:
    void pushElement(int x){
        while(!s1.empty()){
            s2.push(s1.top);
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s1.top);
            s2.pop();
        }
    }
    int popElement(){
        if(s1.empty())  return -1;
        int ele = s1.top();
        s1.pop();
        return ele;
    }

};

/*
APPROACH 1 (using 2 stacks)
- push heavy method

1. for push operation, push element into s1
2. for pop and top operation, 
    if(s2 is not empty) return s2.top
    if(s2 is empty) push all ele from s1 to s2 and return s2.top
    
tc => O(n) sc => O(2*n)
*/
class queueUsingStack{
    stack <int> s1,s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topEle = s2.top();
        s2.pop();
        return topEle;
    }
};