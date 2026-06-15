/*
link: https://leetcode.com/problems/copy-list-with-random-pointer/description/

Copy List with Random Pointer
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.


We need all copyNodes to be created before we connect the next and random pointers
Approach 1
Store ListNode of original array and make a deep copy of the same Node and store in the map 
Then iterate through LL and for everyNode find newly Created copy Node through map and mark its next and random
tc => O(n) + O(n)
sc => O(2*n)

Approach 2
We create the copy nodes and store it in place in one iteration
In another iteration, we connect the random and next pointers and separate the given LL and Copy LL
tc => O(n + 2*n)
sc => O(n)
3 steps
1. Insert Copy Nodes in between
2. Connect Random Pointers (for copyNodes)
3. Connect Next Pointers (for copyNodes) and reset next pointers for originalNodes
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertNodes(Node* head){
        Node* temp = head;
        while(temp){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp){
            Node* copyNode = temp->next;
            if(temp->random)
            copyNode->random = temp->random->next;
            else copyNode->random = NULL;
            temp = temp->next->next;
        }
    }

    Node* getCopiedLL(Node* head){
        Node* dummyNode = new Node(-1);
        Node* copyList = dummyNode;
        Node* temp = head;
        while(temp){    
            copyList->next = temp->next;
            copyList = copyList->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }

public:
    Node* copyRandomList(Node* head) {
        insertNodes(head);
        connectRandomPointers(head);
        return getCopiedLL(head);
    }
};
