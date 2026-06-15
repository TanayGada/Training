/*
link: https://leetcode.com/problems/odd-even-linked-list/description/

Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

We make two LL within given LL
one having all even indexed elements and other having odd indexed elements
We at the end connect even indexed elements LL end to odd indexed elements LL head and return the head of even indexed elements LL
While making these individual LL, we traverse alternate elements as parity pf every alternate element is same.
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)  return NULL;
        if(head->next ==NULL)   return head;
        if(head->next->next==NULL)  return head;
        ListNode* even = head;
        ListNode* evenHead = even;
        ListNode* odd = head->next;
        ListNode* oddHead = odd;
        while(even->next && odd->next){
            if(even->next)  even->next = even->next->next;
            
            if(odd->next)   odd->next = odd->next->next;
            if(even->next)even = even->next;
            if(odd->next)odd = odd->next;
        }
        even->next = oddHead;
        return evenHead;
        
        
    }
};