// study this
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> postorder;
        while(curr){
            if(curr->right==NULL){
                postorder.push_back(curr->val);
                curr = curr->left;
            }
            else{
                TreeNode* prev = curr->right;
                while(prev->left && prev->left!=curr) prev = prev->left;
                if(prev->left==NULL){
                    postorder.push_back(curr->val);
                    prev->left = curr;
                    curr = curr->right;
                }
                else if(prev->left==curr){
                    prev->left = NULL;
                    curr = curr->left; 
                }
            }
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};