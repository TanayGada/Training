// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/1888986922/
// memoized
// tc -> O(n*2), sc -> O(n*2) + O(n)
class Solution {
public:
    int func(int ind, int stock, vector<int>& prices, vector<vector<int>>& dp, int fee){
        if(ind>=prices.size())  return 0;
        if(dp[ind][stock]!=-1)  return dp[ind][stock];
        if(stock){
            int sell =  prices[ind] + func(ind+1, stock-1, prices, dp, fee);
            int hold = func(ind+1, stock, prices, dp, fee);
            return dp[ind][stock] = max(sell, hold);
        }
        else{
            int buy = max(-prices[ind] -fee + func(ind+1, stock+1, prices, dp, fee), 0);
            int nothing = func(ind+1, stock, prices, dp, fee);
            return dp[ind][stock] = max(buy, nothing);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return func(0, 0, prices, dp, fee);
    }
};

// tabulated
// tc -> O(n*2), sc -> O(n*2)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (3,0));
        for(int ind=n-1; ind>=0; ind--){
            for(int stock=1; stock>=0; stock--){
                if(stock){
                    int sell =  prices[ind] + dp[ind+1][stock-1];
                    int hold = dp[ind+1][stock];
                    dp[ind][stock] = max(sell, hold);
                }
                else{
                    int buy = max(-prices[ind] -fee + dp[ind+1][stock+1], 0);
                    int nothing = dp[ind+1][stock];
                    dp[ind][stock] = max(buy, nothing);
                }
            }
        }
        return dp[0][0];
    }
};


// space optmized
// tc -> O(n*2), sc -> O(2*2)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>next (3,0);
        for(int ind=n-1; ind>=0; ind--){
            vector<int>curr (3,0);
            for(int stock=1; stock>=0; stock--){
                if(stock){
                    int sell =  prices[ind] + next[stock-1];
                    int hold = next[stock];
                    curr[stock] = max(sell, hold);
                }
                else{
                    int buy = max(-prices[ind] -fee + next[stock+1], 0);
                    int nothing = next[stock];
                    curr[stock] = max(buy, nothing);
                }
            }
            next = curr;
        }
        return next[0];
    }
};