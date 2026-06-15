/*
link: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

Add 1 to a Linked List Numbe
Given an array, arr[] of digits where each element corresponds to a node in the linked list. You need to add 1 to the number formed by the array. Return the head of the modified linked list. 
Note: The head represents the first element of the given array.

We reverse the LL
We add 1 to firstNode(newHead) value and then add carry (if available) to next nodes
we check if carry is present and LL is completed, and then add a newNode with value=carry
*/

class Solution {
    private:
    Node* reverseLL(Node* head){
        Node* curr = head, *prev = NULL;
        while(curr){
            Node* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node* newHead = reverseLL(head);
        int carry = 0;
        Node* temp = newHead;
        while(temp->next){
            int sum = ((temp==newHead)?1:0)+temp->data+carry;
            carry = sum/10;
            sum = sum%10;
            temp->data = sum;
            temp = temp->next;
        }
        if(carry){
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
        head = reverseLL(newHead);
        return head;
    }
};