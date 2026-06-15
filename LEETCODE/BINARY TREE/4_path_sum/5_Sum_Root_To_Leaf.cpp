// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
// keep track of sum of path, moment path reach leaf, add to totalSum
// tc -> O(n), sc -> O(n)

class Solution {
public:
    void dfs(TreeNode* root, int& totalSum, int& sum){
        if(!root)   return;

        sum = (sum*10) + root->val;
        if(!root->left && !root->right){
            cout<<"hi: "<<sum<<endl;
            totalSum += sum;
        }
        if(root->left)  dfs(root->left, totalSum, sum);
        if(root->right)  dfs(root->right, totalSum, sum);
        sum = (sum/10);
    }
    int sumNumbers(TreeNode* root) {
        int totalSum = 0, sum = 0;
        dfs(root, totalSum, sum);
        return totalSum;
    }
};