// func(curr, prev) -> length of LIS starting from index "curr" and previous index is "prev"

// memoized
// tc -> O(n*n), sc -> O(n*n) + O(n)
class Solution {
public:
    int func(int curr, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(curr==nums.size())   return 0;
        if(dp[curr][prev+1]!=-1)  return dp[curr][prev+1];
        int take = 0;
        if(prev==-1 || nums[prev]<nums[curr])  take = 1 + func(curr+1, curr, nums, dp);
        int notTake = func(curr+1, prev, nums, dp);
        return dp[curr][prev+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return func(0, -1, nums, dp);
    }
};


// tabulated
// tc -> O(n*n), sc -> O(n*n) 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int take = 0;
                if(prev==-1 || nums[prev]<nums[curr])  take = 1 + dp[curr+1][curr+1];
                int notTake = dp[curr+1][prev+1];
                dp[curr][prev+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};

// space optimized
// tc -> O(n*n), sc -> O(2*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1 (n+1, 0);
        for(int curr=n-1; curr>=0; curr--){
            vector<int>dp2 (n+1, 0);
            for(int prev=curr-1; prev>=-1; prev--){
                int take = 0;
                if(prev==-1 || nums[prev]<nums[curr])  take = 1 + dp1[curr+1];
                int notTake = dp1[prev+1];
                dp2[prev+1] = max(take, notTake);
            }
            dp1 = dp2;
        }
        return dp1[0];
    }
};

// tabulated (direct bottom up)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp (n+1, 1);
        int maxi = 0;
        for(int curr=0; curr<n; curr++){
            for(int prev=0; prev<curr; prev++){
                if(nums[prev]<nums[curr])   dp[curr] = max(dp[curr], 1+dp[prev]);
            }
            maxi = max(maxi, dp[curr]);
        }
        return maxi;
    }
};
