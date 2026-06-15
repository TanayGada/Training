// link: https://leetcode.com/problems/house-robber/
// to get non adjacent states, we use pick, not pick method
// if we pick current state, we need curr-2 state, else we need curr-1 state
// memoized
// tc -> O(n), sc -> O(n) + O(n)
class Solution {
public:
    int func(int ind, vector<int>& nums, vector<int>& dp){
        if(ind==0)  return nums[ind];
        if(ind<0)   return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind] + func(ind-2, nums, dp);
        int not_pick = func(ind-1, nums, dp);
        return dp[ind] = max(pick, not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(n-1, nums, dp);
    }
};


// tabulated
// tc->O(n), sc ->O(n)
int rob(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int neg = 0;
    for(int i=1; i<n; i++){
        int pick = nums[i]+(i==1?neg:dp[i-2]);
        int not_pick = dp[i-1];
        dp[i] = max(pick, not_pick);
    }
    return dp[n-1];
}

//space optimized
//tc->O(n), sc ->O(1)
int rob(vector<int>& nums){
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;
    int curr = prev1;
    vector<int> dp(n, 0);
    int neg = 0;
    for(int i=1; i<n; i++){
        int pick = nums[i]+(i==1?neg:prev2);
        int not_pick = prev1;
        curr = max(pick, not_pick);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}