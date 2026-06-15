// https://leetcode.com/problems/average-of-levels-in-binary-tree/
// level order traersal
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*> qt;
        qt.push(root);
        vector<double> ans;
        while(!qt.empty()){
            int sz = qt.size();
            double level = 0;
            for(int i=0; i<sz; i++){
                TreeNode* temp = qt.front();
                qt.pop();
                level += (temp->val);
                if(temp->left)  qt.push(temp->left);
                if(temp->right)  qt.push(temp->right);
            }
            ans.push_back(level/sz);
        }
        return ans;
    }
};