/*
Insertion in a LL
1. head
2. kth element
3. tail
4. Insert Before value x (value x is always present)

Few Cases to Consider
1. LL is empty (there is no head)
2. There is only one element (only head is present)
3. If we need to insert at position 1
*/

Node* insertBeforeHead(Node* head, int newHeadValue){
    Node* newHead = new Node(newHeadValue,nullptr);
    newHead->next = head;
    return newHead;
}

Node* insertTail(Node* head, int newTailValue){
    
    Node* newTail = new Node(newTailValue, nullptr);
    if(head==NULL)  return newTail;     //there is no element in LL
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp ->next = newTail;
    return head;
}

Node* insertAtKthPosition(Node*head, int eleValue, int position){
    Node* newNode = new Node(eleValue,nullptr);
    if(head==NULL)//LL is empty
    {
        if(k==1)    return newNode; 
        else return NULL;
    }
    int currPos = 1;
    if(position==1) return insertBeforeHead(head, eleValue);
    Node* temp = new Node(eleValue, nullptr);
    while(temp){
        if(currPos==k-1){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        currPos++;
        temp = temp->next;
    }
    return head;
}


Node* insertBeforeXValue(Node* head, int x, int valueToInsert){
    Node* newNode = new Node(eleValue,nullptr);
    if(head==NULL) //LL is empty=> this case is not possible
    {
        return NULL;
    }
    if(head->data==x) return insertBeforeHead(head, eleValue);
    Node* temp = new Node(eleValue, nullptr);
    while(temp->next){
        if(temp->next->data==x){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}