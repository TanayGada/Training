// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/1840412826/
class Solution {
public:
    // tc -> O(n), sc -> O(n)
    void recursive(TreeNode* root, TreeNode*& prev){
        if(!root)   return;
        recursive(root->right, prev);
        recursive(root->left, prev);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }

    // tc -> O(n), sc -> O(1)
    void morris(TreeNode*& root){
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right)  prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }

    void flatten(TreeNode* root) {
        if(!root)   return;
        // TreeNode* prev = NULL;
        // recursive(root, prev);
        morris(root);
    }   
};