//https://leetcode.com/problems/partition-equal-subset-sum/description/
// similar to subset sum equal k, 
// building 2 equal subsets is equivalent to building 1 subset with sum = total_sum/2
// func(ind, target) -> whether target is possible till index ind
//memoized
// tc -> O(n*sum/2), sc ->O(n*sum/2) + O(n)
class Solution {
public:
    int func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target==0){
            return 1;
        }
        if(ind==0)  return target==arr[0];
        if(dp[ind][target]!=-1) return dp[ind][target];
        int pick = 0;
        if(target-arr[ind]>=0)  pick = func(ind-1, target-arr[ind], arr, dp);
        int not_pick = func(ind-1, target, arr, dp);
        return dp[ind][target] = (pick||not_pick);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums)   sum += i;
        if(sum&1)   return false;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return func(n-1, sum, nums, dp);
    }
};

// tabulated
// tc -> O(n*sum/2), sc ->O(n*sum/2)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums)   sum += i;
        if(sum&1)   return false;
        sum /= 2;
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        if(nums[0]<=sum)    dp[0][nums[0]] = true;
        for(int ind=1; ind<n; ind++){
            for(int target=1; target<=sum; target++){
                bool pick = false;
                if(target>=nums[ind])  pick = dp[ind-1][target-nums[ind]];
                bool not_pick = dp[ind-1][target];
                dp[ind][target] = (pick|not_pick);
            }
        }
        return dp[n-1][sum];
    }
};

// space optmized
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums)   sum += i;
        if(sum&1)   return false;
        sum /= 2;
        vector<bool> prev(sum+1, false);
        if(nums[0]<=sum)    prev[nums[0]] = true;
        for(int ind=1; ind<n; ind++){
            vector<bool> curr(sum+1, false);
            curr[0] = true;
            for(int target=1; target<=sum; target++){
                bool pick = false;
                if(target>=nums[ind])  pick = prev[target-nums[ind]];
                bool not_pick = prev[target];
                curr[target] = (pick|not_pick);
            }
            prev = curr;
        }
        return prev[sum];
    }
};