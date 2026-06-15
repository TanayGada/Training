// link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// func(ind, target) -> whether target is possible till index ind
// memoized
// tc -> O(n*target), sc ->O(n*target) + O(n)
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
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return func(n-1, sum, arr, dp);
    }
};

// tabulated
// tc -> O(n*sum), sc ->O(n*sum)
bool isSubsetSum(vector<int>& arr, int sum) {
    // code here
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int ind=1; ind<n; ind++){
        for(int target=1; target<=sum; target++){
            bool pick = false;
            if(target>=arr[ind])  pick = dp[ind-1][target-arr[ind]];
            bool not_pick = dp[ind-1][target];
            dp[ind][target] = (pick|not_pick);
        }
    }
    return dp[n-1][sum];
}

// space optmixed
// tc -> O(n*sum), sc ->O(2*sum)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool> prev(sum+1, false);
        prev[0] = true;
        prev[arr[0]] = true;
        for(int ind=1; ind<n; ind++){
            vector<bool> curr(sum+1, false);
            curr[0] = true;
            for(int target=1; target<=sum; target++){
                bool pick = false;
                if(target>=arr[ind])  pick = prev[target-arr[ind]];
                bool not_pick = prev[target];
                curr[target] = (pick|not_pick);
            }
            prev = curr;
        }
        return prev[sum];
    }
};