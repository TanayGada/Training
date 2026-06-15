// goal: max profit
// constraint: 1. atmost 2 transactions
//             2. can hold max 1 stock at an instance

// memoized
// tc -> O(n*2*3), sc -> O(n*2*3) + O(n)
class Solution {
public:
    int func(int ind, int stock, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind==prices.size()) return 0;
        if(dp[ind][stock][cnt]!=-1) return dp[ind][stock][cnt];
        if(stock){ //bought stock in past
            int hold = func(ind+1, 1, cnt, prices, dp);
            int sell = prices[ind] + func(ind+1, 0, cnt-1, prices, dp);
            return dp[ind][stock][cnt] = max(hold, sell);
        }
        else{
            int buy = 0;
            if(cnt>0)   buy = max(-prices[ind] + func(ind+1, 1, cnt, prices, dp), 0);
            int nothing = func(ind+1, 0, cnt, prices, dp);
            return dp[ind][stock][cnt] = max(buy, nothing);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3,-1)));
        return func(0, 0, 2, prices, dp);
    }
};

// tabulated
// tc -> O(n*2*3), sc -> O(n*2*3)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));
    for(int ind=n-1; ind>=0; ind--){
        for(int stock=1; stock>=0; stock--){
            for(int cnt=0; cnt<=2; cnt++){
                if(stock){ //bought stock in past
                    int hold = dp[ind+1][1][cnt];
                    int sell = 0;
                    if(cnt>0) sell = prices[ind] + dp[ind+1][0][cnt-1];
                    dp[ind][stock][cnt] = max(hold, sell);
                }
                else{
                    int buy = 0;
                    if(cnt>0)   buy = max(-prices[ind] + dp[ind+1][1][cnt], 0);
                    int nothing = dp[ind+1][0][cnt];
                    dp[ind][stock][cnt] = max(buy, nothing);
                }
            }
        }
    }
    return dp[0][0][2];
}

// space optimized
// tc -> O(n*2*3), sc -> O(2*2*3)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>next (2, vector<int> (3,0));
    for(int ind=n-1; ind>=0; ind--){
        vector<vector<int>>curr (2, vector<int> (3,0));
        for(int stock=1; stock>=0; stock--){
            for(int cnt=0; cnt<=2; cnt++){
                if(stock){ //bought stock in past
                    int hold = next[1][cnt];
                    int sell = 0;
                    if(cnt>0) sell = prices[ind] + next[0][cnt-1];
                    curr[stock][cnt] = max(hold, sell);
                }else{
                    int buy = 0;
                    if(cnt>0)   buy = max(-prices[ind] + next[1][cnt], 0);
                    int nothing = next[0][cnt];
                    curr[stock][cnt] = max(buy, nothing);
                }
            }
        }
        next = curr;
    }
    return next[0][2];
}