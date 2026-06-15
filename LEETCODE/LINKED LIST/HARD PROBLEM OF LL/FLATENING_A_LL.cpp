/*
link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flattening-a-linked-list

Flattening a Linked List

Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer. Look at the printList() function in the driver code for more clarity.

We know merging two sorted list by using 2 pointer approach
We use recursion to reach lastNode and then we merge 2 childNodes list into one and then that oneMergedList with previous ChildList giving us oneSortedList

n => horizontal length
m => max(vertical length)
tc => O(n*merge) + O(2*m)
sc => O(n)
*/


struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeLL(Node* temp1, Node* temp2){
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        while(temp1 && temp2){
            if(temp1->data<=temp2->data){
                temp->bottom = temp1;
                temp = temp1;
                temp1 = temp1->bottom;
            }
            else{
                temp->bottom = temp2;
                temp = temp2;
                temp2 = temp2->bottom;
            }
            
        }
        if(temp1)   temp->bottom = temp1;
        else temp->bottom = temp2;
        
        return dummyNode->bottom;
    }
  
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL || root->next==NULL)  return root;
        Node* newHead = flatten(root->next);
        root = mergeLL(root,newHead);
        return root;
    }
};