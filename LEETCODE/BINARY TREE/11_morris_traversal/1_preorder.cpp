// preorder -> root left right
// if left node is null, add to ans, go right
// while left exists, connect the rightmost node of the left subtree to the curr
// move left
// if connection already exists, remove connection, then move right
// tc -> O(n), sc -> O(1)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr = curr -> right; //if right is null, it will be threaded and move above
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr)  prev = prev->right;
                if(prev->right==NULL){
                    prev->right = curr;
                    inorder.push_back(curr->val);
                    curr = curr->left;
                }
                else if(prev->right==curr){
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};