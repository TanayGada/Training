// https://leetcode.com/problems/binary-tree-right-side-view/
// last element of each level -> iterative level order
// tc -> O(n), sc -> O(n) + O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        vector<int> ans;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int sz = qt.size();
            while(sz--){
                TreeNode* temp = qt.front();
                if(temp->left)  qt.push(temp->left);
                if(temp->right)  qt.push(temp->right);
                if(sz==0)   ans.push_back(temp->val);
                qt.pop();
            }
        }
        return ans;
    }
};