/*
link: https://leetcode.com/problems/palindrome-linked-list/description/

Palindrome Linked List
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.
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
 
 We reach one element before middle node by using slow and fast pointer method
 We reverse the right half of the LL
 We simultaneously iterate from the head of old LL and newHead of the reversed right part
 If we at any point get unequal values, we return not palindromic
 We then again reverse the right part which we reverse to maintain the consistency of the input
 */
class Solution {

private:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL, *curr = head;
        while(curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)  return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first = head;
        ListNode* second = reverseLL(slow->next);
        while(second){
            cout<<first->val<<" "<<second->val<<endl;
            if(first->val!=second->val) return false;
            first = first->next;
            second = second->next;
        }
        reverseLL(slow->next);
        return true;

    }
};