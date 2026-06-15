/*
link: https://leetcode.com/problems/merge-k-sorted-lists/description/

Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

If we sort two sorted LL, and then the resultant LL with next LL
n => noOfLL
n1, n2, n3, .., nn => length of n individual LL
Time Complexity => (n1+n2) + (n1+n2 + n3) + (n1+n2+n3 + n4) + .. + (n1+n2+n3+..+ nn)
=> nn1 + (n-2)n2 + (n-3)n3 + .. + nn
suppose n1=n2=n3=..=nn
tc => n * (n^2) => near about n^3
sc => O(1)

Lets try to optimize it, using min-heap => priorityQueue
Initially PQ stores head of all LL
We get the top of PQ, temp = PQ
We attach temp to dummyNode
we push temp->next to PQ and attach 
and continue

tc => n*logn + (n*m)*logn
sc => O(n)

*/

    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
            pq.push({lists[i]->val, lists[i]});
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(it.second->next)
                pq.push({it.second->next->val, it.second->next});
            temp->next = it.second;
            temp = temp->next;
        }
        return dummyNode->next;
        
    }
};
