/*
link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

We want to delete nth Node from the end of the given LL
But for length we need a O(n) traversal
To avoid this
We take 2 pointers -> first and second
We start first pointer initially
We start second pointer when first pointer reaches n+1th element from start
This is how we keep distance of n+1 between first and second pointer
The second pointer always points to one element before to the element to be deleted by the time first pointer reaches end 
We need to take care of case where element to be deleted is the 1st element of LL
as first pointer ideally pointer one element before but it isnt possible here
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 1;
        if(head==NULL || head->next==NULL)  return NULL;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(temp1){
            if(cnt>n+1){
                temp2 = temp2->next;
            }
            cnt++;
            temp1 = temp1->next;
        }
        if(cnt==n+1){
            return head->next;
        }
        temp2->next = temp2->next->next;
        
        return head;
    }
};