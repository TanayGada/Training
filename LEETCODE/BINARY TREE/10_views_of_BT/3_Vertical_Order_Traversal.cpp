// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// store element based on the column in a multiset during traversal, then extract elements
class Solution {
    void dfs(TreeNode* root, map<int, multiset<pair<int,int>>>& ele, int row, int col){
        if(!root)   return;
        ele[col].insert({row, root->val});
        dfs(root->left, ele, row+1, col-1);
        dfs(root->right, ele, row+1, col+1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int,int>>> ele; //mp[col] = set({row,ele}, {row,ele}, ..)
        int row = 0, col = 0;
        dfs(root, ele, row, col);
        vector<vector<int>> ans;
        for(auto i : ele){
            vector<int> col;
            for(auto j : i.second){
                col.push_back(j.second);
            }
            ans.push_back(col);
        }
        return ans;
    }
};