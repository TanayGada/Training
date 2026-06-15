// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// use level order traversal
// maintain a flag to denote leftToRight and rightToLeft

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> traversal;
        queue<TreeNode*> qt;
        qt.push(root);
        bool leftToRight = true;
        while(!qt.empty()){
            int sz = qt.size();
            vector<int> a(sz,0);
            for(int i=0; i<sz; i++){
                TreeNode* topEle = qt.front();
                qt.pop();
                int ind = (leftToRight? i : sz-1-i);
                a[ind] = topEle->val;
                if(topEle->left)   qt.push(topEle->left);
                if(topEle->right)   qt.push(topEle->right);
            }
            leftToRight=!leftToRight;
            traversal.push_back(a);
        }
        return traversal;
    }
};

1 4 4 2 8
1 3 3 2 4