// similar to 4_count_subsets_sum_equal_target
// s1 + s2 = total
// s1 - s2 = diff, s1>s2
// s1 = diff + s2
// s1 = diff + total-s1
// s1 = (diff+total)/2;
// we need to count subsets with sum = (diff+total)/2;

//memoized
// tc -> O(n*(diff+total)/2), sc -> O(n*(diff+total)/2) + O(n)
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
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int total = 0;
        for(int i : arr)   total += i;
        int n = arr.size();
        if((diff+total)&1)  return 0;
        vector<vector<int>> dp(n, vector<int> ((diff+total)/2+1, -1));
        return func(n-1, (diff+total)/2, arr, dp);
    }
};

// tabulation
// tc -> O(n*(diff+total)/2), sc -> O(n*(diff+total)/2) 
class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int total = 0;
        for(int i : arr)   total += i;
        int n = arr.size();
        if((diff+total)&1)  return 0;
        int target = (diff+total)/2;
        vector<vector<int>> dp(n, vector<int> (target+1,0));
        dp[0][0] = 1;
        if(arr[0]<=target)  dp[0][arr[0]] = 1;
        if(arr[0]==0) dp[0][0]=2;
        for(int ind=1; ind<n; ind++){
            for(int sum=0; sum<=target; sum++){
                int not_pick = dp[ind-1][sum];
                int pick = 0;
                if(arr[ind]<=sum) pick = dp[ind-1][sum-arr[ind]];
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
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int total = 0;
        for(int i : arr)   total += i;
        int n = arr.size();
        if((diff+total)&1)  return 0;
        int target = (diff+total)/2;
        vector<int>prev (target+1,0);
        prev[0] = 1;
        if(arr[0]<=target)  prev[arr[0]] = 1;
        if(arr[0]==0) prev[0]=2;
        for(int ind=1; ind<n; ind++){
            vector<int>curr (target+1,0);
            for(int sum=0; sum<=target; sum++){
                int not_pick = prev[sum];
                int pick = 0;
                if(arr[ind]<=sum) pick = prev[sum-arr[ind]];
                curr[sum] = pick+not_pick;
            }
            prev = curr;
        }
        return prev[target];
    }
};
