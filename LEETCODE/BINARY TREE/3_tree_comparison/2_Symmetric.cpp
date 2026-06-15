// https://leetcode.com/problems/symmetric-tree/
// consider left subtree and right subtree of root
// tc->O(n), sc->O(n) + O(n)

class Solution {
public:

    bool mirror(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)    return true;
        if(!root1 || !root2)    return false;
        return (root1->val==root2->val && mirror(root1->left, root2->right) && mirror(root1->right, root2->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        return mirror(root->left, root->right);
    }
};

