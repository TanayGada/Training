/*
link: https://leetcode.com/problems/reverse-linked-list/

Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

We recursively reduce the array size
We reverse the smaller array and then gradually larger array
We need to maintain and store the newHead for every array
We have head and front (head->next)
We swap these two Node links 
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
        if(head==NULL || head->next==NULL)    return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};
