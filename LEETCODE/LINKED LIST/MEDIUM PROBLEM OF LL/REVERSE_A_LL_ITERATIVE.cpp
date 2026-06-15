/*
link: https://leetcode.com/problems/reverse-linked-list/

Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

We take help of 3 pointers
prev -> for Node before the curr
curr -> for Current Node
back -> for Node next to curr
We change link from pre->curr to curr->prev
then change prev = curr, curr = back
and continue
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr= head, *pre=NULL;
        while(curr!=NULL)
        {
            ListNode* back = curr->next;
            curr->next=pre;
            pre = curr;
            curr=back;
        }
        return pre;
    }
};