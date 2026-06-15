/*
What is a LL?
Arrays are of fixed size
They store elements at contiguous mem loc in heap
We cannot increase or decrease the size of Arr
LL store elements in non-contiguous mem loc in heap
So it can be enlarged more than the arrays

We store data and nextPointer (pointer to next element) in a Node Struct/class
We store a Node struct/class as a pointer

// Struct/Class for Node
class Node{
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){   // constructor to initialize Node Struct
        data = data1;
        next = next1;   
    }
}

int main(){
    Node* newNode = new Node(1, nullptr);
    cout<<newNode<<endl;    => Pointer to node
    cout<<newNode->data<<endl; => data in node
    return 0;
}



Memory Space Used:
32 bit system               |   64 bit system
int => 4 bytes              |   int => 4 bytes
pointer => 4 bytes          |   pointer => 8 bytes



Difference Between Node and Node*

Node newNode = new Node(1, nullptr); => newNode is an Object so it doesnt have pointer, but we can access its data by dot operator
Node* newNode = new Node(1, nullptr) => newNode is a pointer to new Node, we access by -> or this operator


Convert an Array to LL
Node* convertToLL(vector<int> arr){
    Node* head = new Node(arr[0],nullptr);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}


Traverse a LL
int getLengthOfLL(Node* head){
    Node* temp = head;
    int cnt= 0;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
*/