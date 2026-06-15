// https://leetcode.com/problems/minimum-depth-of-binary-tree/
// node which doesnot have left and right children, is called a leaf node
// tc -> N, sc -> N

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        queue<TreeNode*> qt;
        qt.push(root);
        int ans = INT_MAX;
        int level = 1;
        while(!qt.empty()){
            int sz = qt.size();
            while(sz--){
                TreeNode* temp = qt.front();
                qt.pop();
                if(temp->left)  qt.push(temp->left);
                if(temp->right)  qt.push(temp->right);
                if(!temp->left && !temp->right) return level;
            }
            level++;
        }
        return level;
    }
};