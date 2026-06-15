// link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// func(ind, weight) = max val achieved till index ind with max "weight"

// memoized
//tc -> O(n*capacity), sc -> O(n*capacity) + O(n)
class Solution {
  public:
    int func(int ind, int weight, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if(ind==0){
            int quan = (weight/wt[0]);
            return val[0]*quan;
        }
        if(dp[ind][weight]!=-1) return dp[ind][weight];
        int pick_curr = 0;
        if(weight>=wt[ind]) pick_curr = val[ind] + func(ind, weight-wt[ind], val, wt, dp);
        int pick_nxt = func(ind-1, weight, val, wt, dp);
        return dp[ind][weight] = max(pick_curr, pick_nxt);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (capacity+1, -1));
        return func(n-1, capacity, val, wt, dp);
    }
};

// tabulation
//tc -> O(n*capacity), sc -> O(n*capacity)
class Solution {
  public:

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (capacity+1, 0));
        for(int weight=0; weight<=capacity; weight++){
            dp[0][weight] = (weight/wt[0])*val[0];
        }
        for(int ind=1; ind<n; ind++){
            for(int weight=0; weight<=capacity; weight++){
                int pick_curr = 0;
                if(weight>=wt[ind]) pick_curr = val[ind] + dp[ind][weight-wt[ind]];
                int pick_nxt = dp[ind-1][weight];
                dp[ind][weight] = max(pick_curr, pick_nxt);
            }
        }
        return dp[n-1][capacity];
    }
};


// space optimized
class Solution {
  public:

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<int> prev(capacity+1, 0);
        for(int weight=0; weight<=capacity; weight++){
            prev[weight] = (weight/wt[0])*val[0];
        }
        for(int ind=1; ind<n; ind++){
            vector<int> curr(capacity+1, 0);
            for(int weight=0; weight<=capacity; weight++){
                int pick_curr = 0;
                if(weight>=wt[ind]) pick_curr = val[ind] + curr[weight-wt[ind]];
                int pick_nxt = prev[weight];
                curr[weight] = max(pick_curr, pick_nxt);
            }
            prev = curr;
        }
        return prev[capacity];
    }
};