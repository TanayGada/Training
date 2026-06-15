// https://leetcode.com/problems/count-complete-tree-nodes/description/
// for a perfect BT, number of nodes = 2^h - 1
// a tree is a BT, if leftheight of left subtree and rightHeight of right subtree are equal
// if leftHeight of left subtree is more than rightHeight of right subtree, we need to go to left and right nodes and check for perfect BT
// tc -> O(logn * logn), sc -> O(logn)
// height is logN, we are calculating height in logN for logN elements

class Solution {
public:
    int leftHeight(TreeNode* root){
        int height = 0;
        while(root){
            root = root->left;
            height++;
        }
        return height;
    }

    int rightHeight(TreeNode* root){
        int height = 0;
        while(root){
            root = root->right;
            height++;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int left = leftHeight(root);
        int right = rightHeight(root);
        if(left==right) return (1<<left)-1; // left and right are perfect BT
        else { // left = right + 1
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

};