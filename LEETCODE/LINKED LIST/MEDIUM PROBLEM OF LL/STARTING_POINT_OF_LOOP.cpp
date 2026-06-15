/*
link: https://leetcode.com/problems/linked-list-cycle-ii/description/

Linked List Cycle II
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.

We use slow and fast pointer (similar to que for detecting cycle in LL) to get to same Node in cycle
we point slow pointer to the head and fast where it is
We then move slow and fast pointer by one one place and the Node where they meet is the starting Node of the LL
*/


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==NULL)  return NULL;
            if(slow==fast)  break;
        }
        slow = head;
        while(fast && fast->next){
            if(slow==fast)  return slow;
            slow = slow->next;
            fast = fast->next;
        }
        return NULL;
    }
};