/*
link: https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list

Doubly linked list Insertion at given position
Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.


*/

/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here
   Node* newNode = new Node(data);
   if(head==NULL){
       if(pos==1)   head = newNode;
       return;
   }

   Node* temp = head;
   int cnt = 0;
   
   while(temp){
       if(cnt==pos){
           if(temp->next){
            temp->next->prev = newNode;    
           }
           newNode->next = temp->next;
           temp->next = newNode;
           newNode->prev = temp;
       }
       temp = temp->next;
       cnt++;
   }
   
}