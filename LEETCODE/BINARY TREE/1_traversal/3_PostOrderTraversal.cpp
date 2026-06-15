// https://leetcode.com/problems/binary-tree-postorder-traversal/
// left, right, root
// tc -> O(n), sc -> O(n)
class Solution {
public:
    // recursive
    void postOrder(TreeNode* root, vector<int>& traversal){
        if(root==NULL)  return;
        postOrder(root->left, traversal);
        postOrder(root->right, traversal);
        traversal.push_back(root->val);
    }

    //iterative - 1 stack
    vector<int> postOrder(TreeNode* root){
        vector<int> traversal;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr -> left;
            }
            TreeNode* temp = st.top()->right;
            if(temp)    curr = temp;
            else{
                temp = st.top();
                st.pop();
                traversal.push_back(temp->val);
                while(!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    traversal.push_back(temp->val);
                }
            }
        }
        return traversal;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        traversal = postOrder(root);
        return traversal;
    }
};