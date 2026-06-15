// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// check left and right subtree for p, q
// the first time, we get left and right having some value, that node is the LCA
// else if either left or right give some value, that is the root of subtree having p and q and also the LCA
// tc-> O(n), sc->O(n)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(!right)  return left; //p and q are part of left subtree with root as p or q
        else if(!left) return right;  //p and q are part of right subtree with root as p or q
        else{ //right && left -> we got the ancestor
            return root;
        }
    }
};