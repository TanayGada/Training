// link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/1888971880/
// goal -> maximize profit
// constraints -> at any instance, can hold atmax 1 stock
// cannot buy on i+1 day if sold on i

// memoized
// tc -> O(n*2), sc -> O(n*2)
class Solution {
public:
    int func(int ind, int stock, vector<int>& prices, vector<vector<int>>& dp){
        if(ind>=prices.size())  return 0;
        if(dp[ind][stock]!=-1)  return dp[ind][stock];
        if(stock){
            int sell = prices[ind] + func(ind+2, stock-1, prices, dp);
            int hold = func(ind+1, stock, prices, dp);
            return dp[ind][stock] = max(sell, hold);
        }
        else{
            int buy = max(-prices[ind] + func(ind+1, stock+1, prices, dp), 0);
            int nothing = func(ind+1, stock, prices, dp);
            return dp[ind][stock] = max(buy, nothing);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return func(0, 0, prices, dp);
    }
};

// tabulated

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2,0));
        for(int ind=n-1; ind>=0; ind--){
            for(int stock=1; stock>=0; stock--){
                if(stock){
                    int sell = prices[ind] + dp[ind+2][stock-1];
                    int hold = dp[ind+1][stock];
                    dp[ind][stock] = max(sell, hold);
                }
                else{
                    int buy = max(-prices[ind] + dp[ind+1][stock+1], 0);
                    int nothing = dp[ind+1][stock];
                    dp[ind][stock] = max(buy, nothing);
                }
            }
        }
        return dp[0][0];
    }
};


// space optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>next (2,0);
        vector<int>dNext (2,0);
        for(int ind=n-1; ind>=0; ind--){
            vector<int>curr (2,0);
            for(int stock=1; stock>=0; stock--){
                if(stock){
                    int sell = prices[ind] + dNext[stock-1];
                    int hold = next[stock];
                    curr[stock] = max(sell, hold);
                }
                else{
                    int buy = max(-prices[ind] + next[stock+1], 0);
                    int nothing = next[stock];
                    curr[stock] = max(buy, nothing);
                }
            }
            dNext = next;
            next = curr;
        }
        return next[0];
    }
};