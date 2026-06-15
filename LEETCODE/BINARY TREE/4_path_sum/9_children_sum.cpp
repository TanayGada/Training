// https://www.geeksforgeeks.org/problems/children-sum-parent/1
// check if values of right child + left child equals the node value
// tc -> O(n), sc -> O(n)

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(!root || (!root->left && !root->right))   return true;
        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        return ((sum==root->data) && isSumProperty(root->left) && isSumProperty(root->right));
    }
};