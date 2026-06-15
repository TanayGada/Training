// https://leetcode.com/problems/diameter-of-binary-tree/
// diameter is maximum of height of left subtree + height of right subtree over any node
// we pass by reference the diameter variable and update it
// tc: O(n) and sc: O(n)

class Solution {
public:
    int getHeight(TreeNode* root, int& diameter){
        if(!root)   return 0;
        int left = getHeight(root->left, diameter);
        int right = getHeight(root->right, diameter);
        diameter = max(diameter, left+right);
        return 1+max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root){
        int diameter = 0;
        getHeight(root, diameter);
        return diameter;
    }
};