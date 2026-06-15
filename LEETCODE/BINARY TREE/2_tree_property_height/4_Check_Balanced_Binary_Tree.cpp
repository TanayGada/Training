// https://leetcode.com/problems/balanced-binary-tree/description/
// balanced tree -> for every node, | height(left) - hieght(right) | <=1


// we find the height of the tree
// we return -1 as the height if the tree is not balanced otherwise the height
// whenever we get abs(left-right) > 1 -> we return -1 
// tc: O(n) and sc: O(n)
class Solution {
public:
    int heightOfBT(TreeNode* root){
        if(!root)   return 0;
        int left = heightOfBT(root->left);
        int right = heightOfBT(root->right);
        if(abs(left-right)>1)  return -1;
        if(left==-1 || right==-1)   return -1;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
       int height = heightOfBT(root);
       if(height==-1)   return false;
       return true;
    }
};