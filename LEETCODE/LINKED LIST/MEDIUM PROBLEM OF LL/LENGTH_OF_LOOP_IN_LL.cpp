/*
link: https://bit.ly/3dyXL6m

Find Length Of the Loop in LL

I will use slow and fast pointer and continue iteration until I receive slow==fast
The moment I receive fast==slow, I will start a counter and will increment it until again I get slow==fast
this counter leads to the length of the loop

*/

Node* getLengthOfLoop(Node* head){
    Node* slow = head, *fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==NULL)  return 0; //no loop
        if(slow==fast)  break; //loop is there at slow fast at same node inside loop
    }
    int cnt=0;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        cnt++;
        if(slow==fast)  return cnt;        
    }
    return 0;
}

