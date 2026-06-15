// link:
// for every count problem, we write base cases as return 1(if satisfy) else return 0
// f(n-1, target) = no_of_subsequences till index n-1, which give sum = target
// edge case, if arr[0] = 0 && target==0, we can both take and not take, hence return 2

// memoized
// tc -> O(n*target), sc -> O(n*target) + O(n)
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
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (target+1,-1));
        return func(n-1, target, arr, dp);
    }
};

// tabulation
// tc -> O(n*target), sc -> O(n*target)
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
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
// tc -> O(n*target), sc -> O(2*target)
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
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