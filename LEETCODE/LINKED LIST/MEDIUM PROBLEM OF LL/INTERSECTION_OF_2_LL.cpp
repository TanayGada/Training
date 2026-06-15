/*
link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

Intersection of Two Linked Lists
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

The test cases are generated such that there are no cycles anywhere in the entire linked structure.
Note that the linked lists must retain their original structure after the function returns.

Approach 1
We can get the length (n1,n2) of both LL
suppose n1>n2 => LL1 is greater than LL2
We get the difference = n1-n2
We have 2 pointers temp1 and temp2, initially pointing to head of both LL
We initially move temp1 "difference" places ahead and then start moving both temp1 and temp2 ahead by one place and check if temp1==temp2
tc => O(n1) + O(n2) + (n2)

We can optimize it
We move both temp1 and temp2 by one place 
At each step, we check if temp1==temp2
If temp1 becomes null, we point temp1 to head2
If temp2 becomes null, we point temp2 to head1
This way too we can get the first intersection node
edge cases => both LL are of equal length, any or both LL is empty, there is no intersection, the intersection Node is the 1st Node of both LL
fow proof ki t1 and t2 comes at same level after reaching null and pointing to opposite head, https://youtu.be/0DYoPz2Tpt4?t=1793
tc => O(n1 + n2)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA, *temp2 = headB;
        while(temp1!=temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
            if(temp1==temp2)    return temp1;
            if(temp1==NULL) temp1 = headB;
            if(temp2==NULL) temp2 = headA;
        }
        return temp1;
    }
};