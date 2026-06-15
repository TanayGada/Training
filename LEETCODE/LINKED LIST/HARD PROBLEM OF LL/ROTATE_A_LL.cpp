/*
link: https://leetcode.com/problems/rotate-list/description/

Rotate List
Given the head of a linked list, rotate the list to the right by k places.

suppose LL is => 1 2 3 4 5 6
     final LL => 5 6 1 2 3 4    k=2
     final LL => 4 5 6 1 2 3    k=3
    We see head is kth element from back of LL
    i.e (length-k)th element from start
    for values of k>length, we use modulus function
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(head==NULL)  return NULL;
        int length = 1;
        while(temp->next){
            temp = temp->next;
            length++;
        }
        temp->next = head;
        k = k%length;
        temp = head;

        for(int i=0;i<length-k-1;i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};