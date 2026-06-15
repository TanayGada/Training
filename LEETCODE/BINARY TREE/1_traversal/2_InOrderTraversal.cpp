//https://leetcode.com/problems/binary-tree-inorder-traversal/
// left, root, right
// tc -> O(n), sc -> O(n)
class Solution {
public:
    // recursive
    void inOrder(TreeNode* root, vector<int>& traversal){
        if(root==NULL)  return;
        inOrder(root->left, traversal);
        traversal.push_back(root->val);
        inOrder(root->right, traversal);
    }
    
    // iterative
    vector<int> inOrder(TreeNode* root){
        vector<int> traversal;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(!st.empty() || curr){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            traversal.push_back(curr->val);
            curr = curr->right;
            
        }
        return traversal;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        traversal = inOrder(root);
        return traversal;
    }
};