// https://leetcode.com/problems/path-sum-ii/description/
// path requirement is from root to leaf (and not root to any node)
// node values can be negative
// tc -> O(n*n), extra n for appending path to paths, sc -> O(n), 

class Solution {
public:
    void isPath(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& paths){
        if(!root)   return;
        
        path.push_back(root->val);
        if(!root->left && !root->right && target == 0){
            paths.push_back(path);
        }
        
        if(root->left){
            isPath(root->left, target-root->left->val, path, paths);
        }
        if(root->right){
            isPath(root->right, target-root->right->val, path, paths);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)   return {};
        vector<vector<int>> paths;
        vector<int> path;
        isPath(root, targetSum-root->val, path, paths);
        return paths;
    }
};