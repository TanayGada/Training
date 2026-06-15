/*
link: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list

Find pairs with given sum in doubly linked list

Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

2 Methods
1.  We solve it as if it is a sorted array and we need to find all pairs with given sum
    We use basic O(n^2) solution approach
    for every temp1, we check temp2(other elements>temp1) whether they form a pair or not
2. 2 Pointer Approach as it it sorted
    right pointer and left pointer
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node* temp1 = head;
        vector<pair<int,int>> ans;
        while(temp1){
            Node* temp2 = temp1->next;
            while(temp2){
                if(temp1->data+temp2->data>target){
                    break;
                }
                if(temp1->data+temp2->data==target){
                    ans.push_back({temp1->data, temp2->data});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return ans;
    }
};




// 2 Pointer Solution
class Solution
{
    
private:
    Node* getTail(Node* head){
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        return temp;
    }
    
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node* left = head, *right = getTail(head);
        vector<pair<int,int>> ans;
        while(left->data<right->data){
            if(left->data+right->data==target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data+right->data>target){
                right = right->prev;
            }
            else{
                left = left->next;
            }
        }
        return ans;
    }
};
