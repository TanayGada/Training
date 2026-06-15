/*
link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

Reverse Nodes in k-Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

We get nodes in k size group detached from LL, We reverse them and then attach them
We continue this process until we donot find k size group of nodes

ALGORITHM
1. initially temp = head,
   prev = NULL,
2. while(temp){
    kthNode = getKthNode(temp) => last node of k size group
    if (kthNode==NULL){
        prev->next = temp;
        break;
    }
    else{
        nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);
        if(temp==head){
            head = kthNode;
        }
        else{
            prev->next = kthNode;
        }
        prev = temp;
        temp = nextNode;
    }
   }
*/


class Solution {

private:
    ListNode* getKthNode(ListNode* temp, int k){
        for(int i=0;i<k-1;i++)   if(temp){ temp = temp->next;}
        return temp;
    }

    void reverseLL(ListNode* temp){
        ListNode* prev = NULL;
        while(temp){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevNode = NULL, *temp = head;
        while(temp){
            ListNode* kthNode = getKthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode)    prevNode->next = temp;
                break;
            }
            else{
                ListNode* nextNode = kthNode->next;
                kthNode->next = NULL;
                reverseLL(temp);
                if(temp==head){
                    head = kthNode;
                }
                else{
                    if(prevNode)    prevNode->next = kthNode;
                }
                prevNode = temp;
                temp = nextNode;
            }
        }
        return head;
    }
};