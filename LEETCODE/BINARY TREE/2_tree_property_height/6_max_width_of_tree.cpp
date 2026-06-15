//
// index nodes in tree
// index each level starting from 0 -> otherwise maxIndex = 2^N, N is 100, overflow
// index all nodes on every level based on the 1st node on that level
// tc -> O(n), sc ->O(n)

class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        queue<pair<TreeNode*, long long>> qt;
        qt.push({root, 0}); //node, index
        long long width = 0;
        while(!qt.empty()){
            int sz = qt.size();
            long long index = qt.front().second;
            long long mini = LLONG_MAX, maxi = LLONG_MIN;
            for(int i=0; i<sz; i++){
                auto ele = qt.front();
                qt.pop();
                long long curr_index = ele.second-index;
                TreeNode* temp = ele.first;
                mini = min(mini, curr_index);
                maxi = max(maxi, curr_index);
                if(temp->left)  qt.push({temp->left, curr_index*2+1});
                if(temp->right)  qt.push({temp->right, 2*(curr_index+1)});
            }
            width = max(width, maxi-mini+1ll);
        }
        return width;
    }
};