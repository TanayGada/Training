/*
link: https://leetcode.com/problems/add-two-numbers/description/

Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

We maintain a carry and sum variable
carry is sum/10
and sum is value from both list and the prevCarry(carry)
To handle cases when len(l1)<len(l2), we take l1->value =0
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        int carry = sum/10;
        sum %= 10;
        ListNode* newHead = new ListNode(sum);
        ListNode* temp = newHead;
        ListNode* temp1 = l1->next;
        ListNode* temp2 = l2->next;
        while(temp1 || temp2 ||carry){
            int val1 = temp1? temp1->val : 0;
            int val2 = temp2? temp2->val: 0; 
            int sum =  val1 + val2 + carry;
            carry = sum/10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = newNode;
            if(temp1)   temp1 = temp1->next;
            if(temp2)   temp2 = temp2->next;  
        }
        return newHead;
    }
};