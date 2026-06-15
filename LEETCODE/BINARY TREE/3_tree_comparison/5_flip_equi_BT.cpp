// https://leetcode.com/problems/flip-equivalent-binary-trees/description/
// tc -> O(n), sc->O(height)
// 2 cases: immediate children are swapped or not swapped
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)    return true;
        if(!root1 || !root2)    return false;
        if(root1->val!=root2->val)  return false;
        
        bool noSwap = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool swap = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        return swap || noSwap;
    }
};