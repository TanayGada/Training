// link: https://leetcode.com/problems/min-cost-climbing-stairs/
// i need to reach stair n-2 or n-1, from where i can get to n stair in 0 cost
// for each current state, we can either jump from curr-1 or curr-2 state
// memoized
// tc ->O(n), sc ->O(n) + O(n)
class Solution {
public:
    int func(int ind, vector<int>& cost, vector<int>& dp){
        if(ind<0)   return 0;
        if(ind==0 || ind==1)  return cost[ind];
        if(dp[ind]!=-1) return dp[ind];
        int one = cost[ind] + func(ind-1, cost, dp);
        int two = cost[ind] + func(ind-2, cost, dp);
        return dp[ind] = min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(func(n-1, cost, dp), func(n-2, cost, dp));
    }
};


// tabulated
//tc -> O(n), sc ->O(n)
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n,0);
    dp[0] = cost[0];
    if(n>1) dp[1] = cost[1];
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
    }
    return min(dp[n-1], dp[n-2]);
}

//optimization
//tc -> O(n), sc ->O(1)
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int one = cost[0];
    int two = cost[1];
    int curr = 0;
    for(int i=2; i<n; i++){
        curr = min(one, two) + cost[i];
        one = two;
        two = curr;
    }
    return min(one, two);
}