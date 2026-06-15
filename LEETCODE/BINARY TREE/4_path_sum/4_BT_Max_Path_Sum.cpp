// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// final ans can be -> left subtree, right subtree, root, left+right+root
// we return the largest path a node can contain which can be continued -> left+root, right+root, root
// tc -> O(N), sc -> O(n)

class Solution {
public:
    int dfs(TreeNode* root, int& maxi){
        if(!root)   return 0;
        int left = dfs(root->left, maxi);
        int right = dfs(root->right, maxi);
        maxi = max({maxi, right+root->val, left+root->val, left+right+root->val, root->val});
        return max({left, right, 0}) + root->val; // we leave left or right subtree if its neg and simply add the root
    }
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        dfs(root, maxPathSum);
        return maxPathSum;
    }   
};
