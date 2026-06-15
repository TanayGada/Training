//link: https://leetcode.com/problems/target-sum/

// its like selecting 2 subsets s1 and s2, then sum(s1) - sum(2) = target
// similar to 5_Count_Partition_With_Given_Diff
// if target is very large negative or very large positive, i.e abs(target) > sum(arr), not possible

//memoized
// tc -> O(n*(target+total)/2), sc -> O(n*(target+total)/2) + O(n)
class Solution {
public:
        int func(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(ind==0){
            if(sum==0 && arr[0]==0) return 2;
            if(sum==0 || arr[0]==sum) return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1)    return dp[ind][sum];
        int not_pick = func(ind-1, sum, arr, dp);
        int pick = 0;
        if(arr[ind]<=sum) pick = func(ind-1, sum-arr[ind], arr, dp);
        return dp[ind][sum] = pick+not_pick;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i : nums)   total += i;
        int n = nums.size();
        if(abs(target)>total)   return 0;
        if((target+total)&1)  return 0;
        vector<vector<int>> dp(n, vector<int> ((target+total)/2+1, -1));
        return func(n-1, (target+total)/2, nums, dp);
    }
};



// tabulation
// tc -> O(n*(diff+total)/2), sc -> O(n*(diff+total)/2) 
class Solution {
  public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i : nums)   total += i;
        int n = nums.size();
        if(abs(target)>total)   return 0;
        if((target+total)&1)  return 0;
        target = (target+total)/2;
        vector<vector<int>> dp(n, vector<int> (target+1,0));
        dp[0][0] = 1;
        if(nums[0]<=target)  dp[0][nums[0]] = 1;
        if(nums[0]==0) dp[0][0]=2;
        for(int ind=1; ind<n; ind++){
            for(int sum=0; sum<=target; sum++){
                int not_pick = dp[ind-1][sum];
                int pick = 0;
                if(nums[ind]<=sum) pick = dp[ind-1][sum-nums[ind]];
                dp[ind][sum] = pick+not_pick;
            }
        }

        return dp[n-1][target];
    }
};


// space optimized
// tc -> O(n*(diff+total)/2), sc -> O(2*(diff+total)/2) 
class Solution {
  public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i : nums)   total += i;
        int n = nums.size();
        if(abs(target)>total)   return 0;
        if((target+total)&1)  return 0;
        target = (target+total)/2;
        vector<int>prev (target+1,0);
        prev[0] = 1;
        if(nums[0]<=target)  prev[nums[0]] = 1;
        if(nums[0]==0) prev[0]=2;
        for(int ind=1; ind<n; ind++){
            vector<int>curr (target+1,0);
            for(int sum=0; sum<=target; sum++){
                int not_pick = prev[sum];
                int pick = 0;
                if(nums[ind]<=sum) pick = prev[sum-nums[ind]];
                curr[sum] = pick+not_pick;
            }
            prev = curr;
        }

        return prev[target];
    }
};