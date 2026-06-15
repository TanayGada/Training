// link: https://leetcode.com/problems/unique-paths/description/

//memoized
// tc -> O(n*m), sc -> O(n*m) + O(n*m) stack space
class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0)    return 1;
        if(i<0 || j<0)  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int up = func(i-1, j, dp);
        int left = func(i, j-1, dp);
        return dp[i][j] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return func(m-1, n-1, dp);
    }
};

// tabulation
// tc -> O(n*m), sc -> O(n*m) 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,0));
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i>0) dp[i][j] += dp[i-1][j];//down
                if(j>0) dp[i][j] += dp[i][j-1];//right
            }
        }
        return dp[m-1][n-1];
    }
};


// space optimized
// tc -> O(n*m), sc -> O(n+m) 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        for(int& i : prev)   i=1;
        for(int i=1; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                if(j==0)    curr[j] = prev[j];
                if(j>0) curr[j] += curr[j-1] + prev[j];//right
            }
            prev = curr;
        }
        return prev[n-1];
    }
};