// https://leetcode.com/problems/leaf-similar-trees/description/
// get leaves for both trees tc-> O(n + m), sc->max(n,m)
class Solution {
public:
    void getSeq(TreeNode* root, vector<int>& leaves){
        if(!root)   return;
        if(!root->left && !root->right) leaves.push_back(root->val);
        if(root->left)  getSeq(root->left, leaves);
        if(root->right)  getSeq(root->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        getSeq(root1, leaves1);
        vector<int> leaves2;
        getSeq(root2, leaves2);
        return leaves1==leaves2;
    }
};