// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// for the curr node, we calculate the max height of left tree and 
// max height of right tree and take the max and add 1 for curr node

// tc-> O(n), sc->O(n)
class Solution {
public:
    int getDepth(TreeNode* root){
        if(!root)   return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return max(leftDepth, rightDepth)+1;
    }

    int maxDepth(TreeNode* root) {
        int depth = getDepth(root);
        return depth;
    }
};