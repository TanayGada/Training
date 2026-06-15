// link: https://leetcode.com/problems/coin-change/
// can be solved using 1d dp

//memoized
// tc -> O(n*amount), sc -> O(n*amount) + O(n)
class Solution {
public:
    int func(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
            if(amount%coins[0]==0)   return amount/coins[0];
            return 1e7;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick = 1e7;
        if(coins[ind]<=amount)   pick = 1 + func(ind, amount-coins[ind], coins, dp);
        int not_pick = func(ind-1, amount, coins, dp);
        return dp[ind][amount] = min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int val = func(n-1, amount, coins, dp);
        return (val==1e7? -1 : val);
    }
};


// tabulated
// tc -> O(n*amount), sc -> O(n*amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int target=0; target<=amount; target++){
            if(target%coins[0]==0)   dp[0][target] = target/coins[0];
            else dp[0][target] = 1e7;
        }
        for(int ind=1; ind<n; ind++){
            for(int target=0; target<=amount; target++){
                int pick = 1e7;
                if(coins[ind]<=target)   pick = 1 + dp[ind][target-coins[ind]];
                int not_pick = dp[ind-1][target];
                dp[ind][target] = min(pick, not_pick);
            }
        }
        return (dp[n-1][amount]==1e7? -1 : dp[n-1][amount]);
    }
};

// space optmized
// tc -> O(n*amount), sc -> O(2*amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0);
        for(int target=0; target<=amount; target++){
            if(target%coins[0]==0)   prev[target] = target/coins[0];
            else prev[target] = 1e7;
        }
        for(int ind=1; ind<n; ind++){
            vector<int> curr = prev;
            for(int target=0; target<=amount; target++){
                int pick = 1e7;
                if(coins[ind]<=target)   pick = 1 + curr[target-coins[ind]];
                int not_pick = prev[target];
                curr[target] = min(pick, not_pick);
            }
            prev = curr;
        }
        return (prev[amount]==1e7? -1 : prev[amount]);
    }
};