/*
link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

Delete the Middle Node of a Linked List
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

We use 2 pointer, one slow and one fast pointer
Slow pointer moves by one Node
Fast Pointer moves by two Nodes
Whenever Fast Pointer reaches the last or second-last Node, the slow points to the middle element
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)  return NULL;
        ListNode* slow = head, *fast = head, *prev=NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete(slow);
        return head;
    }
};