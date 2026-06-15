// https://leetcode.com/problems/path-sum-iii/description/
// consider this problem as, finding subarray sum equal to targetSum in a 1d array 
// tc -> O(n), sc -> O(n) + O(n)
class Solution {
public:
    void dfs(TreeNode* root, int& target, map<long long,int>& mp, int& cnt, long long& sum){
        if(!root)   return;
        sum += root->val;
        cout<<sum<<endl;
        if(mp.count(sum-target))    cnt+=mp[sum-target];
        if(sum==target) cnt++;
        mp[sum]++;
        if(root->left)  dfs(root->left, target, mp, cnt, sum);
        if(root->right)  dfs(root->right, target, mp, cnt, sum);
        mp[sum]--;
        if(mp[sum]==0)    mp.erase(sum);
        sum-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        map<long long,int> mp;
        long long sum = 0;
        dfs(root, targetSum, mp, cnt, sum);
        return cnt;
    }
};