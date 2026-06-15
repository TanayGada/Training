/*
link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

Reverse a Doubly Linked List
Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.

We need to reverse all the links so that the originalTail becomes the newHead and originalHead becomes newTail
*/
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        Node* temp = head;
        while(temp){
            Node* nextNode = temp->next;
            temp->next = temp->prev;
            temp->prev = nextNode;
            if(temp->prev==NULL)    return temp;
            temp = temp->prev;          
        }
        return head;
    }
};