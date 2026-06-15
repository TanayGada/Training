// https://leetcode.com/problems/binary-tree-preorder-traversal/
// preOrder -> root, left, right
// tc -> O(n), sc -> O(n)
class Solution {
public:
    // recursive
    void preOrder(TreeNode* root, vector<int>& traversal){
        if(root==NULL)  return;
        traversal.push_back(root->val);
        preOrder(root->left, traversal);
        preOrder(root->right, traversal);
    }

    // iterative
    vector<int> preOrder(TreeNode* root){
        vector<int> traversal;
        if(!root) return traversal;
        stack<TreeNode*> st;
        st.push(root); 
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
            traversal.push_back(temp->val);
        }
        return traversal;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        traversal = preOrder(root);
        return traversal;
    }
};