// https://leetcode.com/problems/binary-tree-level-order-traversal/ 
// we keep track of all childs for every nodes at the current level using queue
// tc -> O(n), sc -> O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> qt;
        qt.push(root);
        vector<vector<int>> traversal;
        while(!qt.empty()){
            int size = qt.size();
            vector<int> level;
            while(size--){
                TreeNode* node = qt.front();
                qt.pop();
                level.push_back(node->val);
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
            traversal.push_back(level);
        }
        return traversal;
    }
};