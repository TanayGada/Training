/*
link: https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-doubly-linked-list

Convert an array to DLL
Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.
*/

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        if(arr.size()==1)   return head;
        Node* prevNode = head;
        for(int i=1;i<arr.size()-1;i++){
            Node* newNode = new Node(arr[i]);
            prevNode->next = newNode;
            newNode->prev = prevNode;
            prevNode = newNode;
        }
        Node* tail = new Node(arr[arr.size()-1]);
        prevNode->next = tail;
        tail->prev = prevNode;
        return head;
    }
};
