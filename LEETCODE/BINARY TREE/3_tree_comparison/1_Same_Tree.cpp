// https://leetcode.com/problems/same-tree/description/
// use either of traversal techniques
// tc-> O(n), sc->O(n)

class Solution {
public:
    bool dfs(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)    return true;
        if(!root1 || !root2)    return false;
        return (root1->val==root2->val && dfs(root1->left,root2->left) && dfs(root1->right,root2->right));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};