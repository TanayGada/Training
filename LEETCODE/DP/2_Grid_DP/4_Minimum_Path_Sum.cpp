// link: https://leetcode.com/problems/minimum-path-sum/description/
// memoized
//tc -> O(n*m), sc -> O(n*m) + O(n*m)
class Solution {
public:
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0)    return grid[0][0];
        if(i<0 || j<0)  return INT_MAX;
        if(dp[i][j]!=-1)    return dp[i][j];
        int up = func(i-1, j, grid, dp);
        int left = func(i, j-1, grid, dp);
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return func(m-1, n-1, grid, dp);
    }
};

// tabulated
// tc -> O(n*m), sc -> O(n*m)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        dp[0][0] = grid[0][0];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)    continue;
                else if(i==0)    dp[0][j] = grid[0][j] + dp[0][j-1];
                else if(j==0)    dp[i][0] = grid[i][0] + dp[i-1][j];
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// space optimized
// tc -> O(n*m), sc ->O(n*m)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0)    curr[0] = grid[0][0];
                else if(i==0)    curr[j] = grid[0][j] + curr[j-1];
                else if(j==0)    curr[0] = grid[i][0] + prev[j];
                else{
                    curr[j] = min(prev[j], curr[j-1]) + grid[i][j];
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};