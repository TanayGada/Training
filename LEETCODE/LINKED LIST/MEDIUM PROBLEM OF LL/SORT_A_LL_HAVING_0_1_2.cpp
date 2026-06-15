/*
link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

Sort a linked list of 0s, 1s and 2s
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.


We will segregate the given LL into 3 parts
1 having all 0s, 1 having all 1s, 1 having all 2s
We will then attach 0s tail to 1s head and 1s tail to 2s head

We create dummyNode for each 0,1,2 to start with
We then append the nodes of value 0, 1, 2 to respective dummyNode
We then connect 0 list with 1 list with 2 list
We should make sure end of this final list is not pointing to some other element and hence we should avoid cycle by pointing last element to null
*/

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);

        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        Node* temp = head;
        while(temp){
            if(temp->data==0){
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data==1){
                one->next = temp;
                one = one->next;
            }
            else if(temp->data==2){
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        
        zero->next = (oneHead->next)? oneHead->next : (twoHead->next);
        one->next = twoHead->next;
        two->next = NULL;
        Node* newHead = zeroHead->next;
        delete(oneHead);
        delete(zeroHead);
        delete(twoHead);
        return newHead;
    }
};
