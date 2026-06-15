// https://leetcode.com/problems/unique-paths-ii/description/

// memoized
// tc -> O(n*m), sc -> O(n*m) + O(n*m)
class Solution {
public:
    int func(int i, int j, vector<vector<int>>& obstacle, vector<vector<int>>& dp){
        if(i==0 && j==0)    return 1;
        if(i<0 || j<0 || obstacle[i][j])    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int up = func(i-1, j, obstacle, dp);
        int left = func(i, j-1, obstacle, dp);
        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)   return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return func(m-1, n-1, obstacleGrid, dp);
    }
};


// tabulated
// tc -> O(n*m), sc -> O(n*m)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)   return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        dp[0][0] = 1;
        for(int j=1; j<n; j++){
            if(obstacleGrid[0][j]==0)   dp[0][j] = dp[0][j-1];
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==0){
                    if(j==0)    dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// space optimized
// tc -> O(n*m), sc -> O(2*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)   return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);
        prev[0] = 1;
        for(int j=1; j<n; j++){
            if(obstacleGrid[0][j]==0)   prev[j] = prev[j-1];
        }
        for(int i=1; i<m; i++){
            vector<int> curr(n,0);
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==0){
                    if(j==0)    curr[j] = prev[j];
                    else curr[j] = curr[j-1] + prev[j];
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};