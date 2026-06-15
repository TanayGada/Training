/*
link: https://leetcode.com/problems/linked-list-cycle/description/

Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

We use 2 pointer, one slow and one fast pointer
Slow pointer moves by one Node
Fast Pointer moves by two Nodes
Whenever fast pointer == slow Pointer, we tell there is a loop
If fast pointer ==NULL, we tell there is no loop
Why does this always work?
Consider an example, where loop is present, distance from fast to slow (not slow to fast) is always decreasing by 1, means fast will catch up slow from slow's back
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)  return true;
        }
        return false;

        
    }
};