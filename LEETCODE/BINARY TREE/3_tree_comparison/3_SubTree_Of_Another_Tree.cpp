//https://leetcode.com/problems/subtree-of-another-tree/description/
// for each node in root, check whether the subtree having the node as root is equal to subtree given by subRoot
//if there are no duplicates in tree, tc -> O(n+m)
//tc -> O(N*M), sc -> O(n+m)
class Solution {
public:
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)   return true;
        if(!root || !subRoot)   return false;
        return(root->val==subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)   return false;
        if(isSame(root, subRoot))    return true;
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};