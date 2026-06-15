// https://leetcode.com/problems/binary-tree-paths/
// each recursion stack have a string variable
// if a node have no left and right child, that node is leaf node and we got the path
// tc -> O(n), sc -> O(n) -> using inplace string updation, otherwise would be O(H*N)

class Solution {
public:
    void addPath(TreeNode* root, string& s, vector<string>& paths){
        if(!root)   return;
        int len = s.size();
        if(s=="")   s = to_string(root->val);
        else s = s + "->" + to_string(root->val);
        if(!root->left && !root->right){
            paths.push_back(s);
        }
        else{
            addPath(root->left, s, paths);
            addPath(root->right, s, paths);
        }
        s.resize(len);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string s = "";
        addPath(root, s, paths);
        return paths;
    }
};