/*
link: https://leetcode.com/problems/sort-list/description/

Sort List
Given the head of a linked list, return the list after sorting it in ascending order.

We can use merge Sort Algorithm here (similar how we do on arrays)
1. We find middle element (if odd=> middle || if even => one before middle)
2. We then disconnect the left and right LL
3. We keep on doing this
4. We then merge two smaller LL and so on keep on merging until we find the whole sorted LL 
*/

class Solution {
public:
    ListNode* mergeLL(ListNode* list1, ListNode* list2) {
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

    ListNode* getMiddleNode(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;
        ListNode* middleNode = getMiddleNode(head);
        ListNode* leftStart = head, *rightStart = middleNode->next;
        middleNode->next = NULL;
        leftStart = sortList(leftStart);
        rightStart = sortList(rightStart);
        return mergeLL(leftStart, rightStart);
    }
};