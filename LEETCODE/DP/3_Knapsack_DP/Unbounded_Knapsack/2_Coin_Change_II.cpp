// link: https://leetcode.com/problems/coin-change-ii/
// for counting
// base case is return 0/1
// try all posibilities
// return ..... + ......
// for writing recurrence,
// 1. express in terms of index
// func(ind, target) -> till index 0 to ind, how many ways, target is achieved

//memoized
// tc -> O(n*amount), sc -> O(n*amount) + O(n)
class Solution {
public:
    int func(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
            if(target%coins[0]==0)  return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int pick_curr = 0;
        if(target>=coins[ind])   pick_curr = func(ind, target-coins[ind], coins, dp);
        int not_pick = func(ind-1, target, coins, dp);
        return dp[ind][target] = pick_curr + not_pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return func(n-1, amount, coins, dp);
    }
};

// tabulation
// tc -> O(n*amount), sc -> O(n*amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long> (amount+1, 0));
        for(int target=0; target<=amount; target++){
            if(target%coins[0]==0)  dp[0][target] = 1;
        }
        for(int ind=1; ind<n; ind++){
            for(int target=0; target<=amount; target++){
                unsigned long long pick_curr = 0;
                if(target>=coins[ind])   pick_curr = dp[ind][target-coins[ind]];
                unsigned long long not_pick = dp[ind-1][target];
                dp[ind][target] = pick_curr + not_pick;
            }
        }
        return dp[n-1][amount];
    }
};

// space optmized
// tc -> O(n*amount), sc -> O(2*amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> prev(amount+1, 0);
        for(int target=0; target<=amount; target++){
            if(target%coins[0]==0)  prev[target] = 1;
        }
        for(int ind=1; ind<n; ind++){
            vector<unsigned long long> curr = prev;
            for(int target=0; target<=amount; target++){
                unsigned long long pick_curr = 0;
                if(target>=coins[ind])   pick_curr = curr[target-coins[ind]];
                unsigned long long not_pick = prev[target];
                curr[target] = pick_curr + not_pick;
            }
            prev = curr;
        }
        return prev[amount];
    }
};