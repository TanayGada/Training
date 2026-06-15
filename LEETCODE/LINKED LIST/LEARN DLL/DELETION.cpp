/*
link: https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list

Delete node in Doubly Linked List
Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.
*/

/*
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        Node* temp = head;
        if (x == 1) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            return head;
        }
        // Traverse the list to find the xth node
        int cnt = 1;
        while (temp && cnt < x) {
            temp = temp->next;
            cnt++;
        }
        
        // If x is greater than the length of the list
        if (temp == NULL) return head;
        
        // Deleting the xth node
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        
        return head;
    }
};