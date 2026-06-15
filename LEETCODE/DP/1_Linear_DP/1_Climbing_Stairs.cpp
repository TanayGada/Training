//f(n) -> no of ways, i can reach from 0 to n
//f(0) = reach from 0 to 0, 1 way
//f(1) = reach from 1 to 0. 1 way
// we can jump 1 and 2 index
// similar to fibonacci 

// link: https://leetcode.com/problems/climbing-stairs/
// tc -> O(n), sc -> O(n) + O(n)
// memoized

int function(int ind, vector<int>& dp){
    if(ind==0 || ind==1)    return 1;
    if(dp[ind]!=-1) return dp[ind];
    return dp[ind] = function(ind-1, dp) + function(ind-2, dp);
}
int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    function(n, dp);
    return dp[n];
}


//tabulated
// tc -> O(n), sc -> O(n)
int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// space optimization
// tc -> O(n),  sc -> O(1)
int climbStairs(int n) {
    int prev1 = 1;
    int prev2 = 1;
    int curr = 0;
    for(int i=2; i<=n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}