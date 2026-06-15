/*
Deletion in a LL
1. head
2. kth element
3. tail
4. element x
*/

Node* deleteHeadInLL(Node* head){
    if(head==NULL || head->next==NULL)  retun NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL)  return NULL;
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

//we are considering k is less than the length of the LL
Node* deleteKthEle(Node* head, int k){
    if(head==NULL)  return NULL;
    Node* temp = head;
    Node* prev = head;
    int pos = 1;
    if(k==1){
        return deleteHeadInLL(head);
    }
    while(temp){
        if(pos==k){
            prev->next = prev->next->next;
            free(temp);
            break;  
        }
        prev = temp;
        temp = temp->next;
        pos++;
    }
    return head;
}

Node* deleteEleX(Node* head, int x){
    if(head==NULL)  return NULL;
    Node* temp = head;
    Node* prev = NULL;
    if(head->data ==x){
        return deleteHeadInLL(head);
    }
    while(temp){
        if(temp->data == x){
            prev->next = temp->next;
            free(temp);            
            break;
        }
        temp = temp->next;
    }
}