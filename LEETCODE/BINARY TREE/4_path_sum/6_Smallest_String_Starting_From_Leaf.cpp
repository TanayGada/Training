// https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
// maintain current and smallest String,
// tc -> O(n*n), && sc -> O(n*neach time, a new string is constructed using concatenation

class Solution {
public:
    void dfs(TreeNode* root, string& smallest, string current){
        if(!root)   return;
        current = char(root->val+'a') + current;
        if(!root->left && !root->right){
            if(smallest=="")    smallest = current;
            else if(current<=smallest)  smallest = current;
        }
        if(root->left)  dfs(root->left, smallest, current);
        if(root->right)  dfs(root->right, smallest, current);
    }

    string smallestFromLeaf(TreeNode* root) {
        string smallest = "";
        string current = "";
        dfs(root, smallest, current);
        return smallest;
    }
};