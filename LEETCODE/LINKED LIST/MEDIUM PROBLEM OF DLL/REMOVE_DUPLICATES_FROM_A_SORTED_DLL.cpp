/*
link: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list


Remove duplicates from a sorted doubly linked list
Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

We use 2 pointers, currNode and nextNode
We check if they are same, we delete nextNode and continue
If currNode and nextNode are different we change currNode = currNode->next
*/


class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node* temp = head;
        while(temp->next){
            Node* nextNode = temp->next;
                if(temp->data == nextNode->data){
                    temp->next = nextNode->next;
                    if(nextNode->next)  nextNode->next->prev = temp;
                    delete(nextNode);
                }
                else{
                    temp = temp->next;
                }
        }
        return head;
    }
};