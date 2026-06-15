/*
link: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list

Delete all occurrences of a given key in a doubly linked list
You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

*/

/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp = *head_ref;
        while(temp){
            if(temp->data==x){
                if(temp==*head_ref){
                    *head_ref = temp->next;
                    if(*head_ref){
                        (*head_ref)->prev = NULL;
                    }
                }
                else{
                    temp->prev->next = temp->next;
                    if(temp->next){
                        temp->next->prev = temp->prev;
                    }
                }
                Node * toDelete = temp;
                temp = temp->next;
                delete(toDelete);
            }
            else{
                temp = temp->next;    
            }
        }
    }
};