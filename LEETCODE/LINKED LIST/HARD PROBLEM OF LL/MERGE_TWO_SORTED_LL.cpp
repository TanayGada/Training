/*
link: https://leetcode.com/problems/merge-two-sorted-lists/description/

Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Similar to Classical 2 pointer approach to merge 2 sorted arrays

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        ListNode* temp1 = list1, *temp2 = list2;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        while(temp1){
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        while(temp2){
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};