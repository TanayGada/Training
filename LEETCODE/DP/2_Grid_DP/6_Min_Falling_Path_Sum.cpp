// variable starting point and variable ending point

// memoized
// here dp initialized to -1 is giving tle because, there are multiple cases where -1 is the sum
class Solution {
public:
    int getMinPathValue(int row, int col, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(col<0 || col>=n) return INT_MAX;
        if(row==0)  return matrix[row][col];
        if(dp[row][col]!=-10)    return dp[row][col];
        int up = getMinPathValue(row-1, col, n, matrix, dp);
        int left = getMinPathValue(row-1, col-1, n, matrix, dp);
        int right = getMinPathValue(row-1, col+1, n, matrix, dp);
        return dp[row][col] = min({up, right, left}) + matrix[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int min_path = INT_MAX;
        for(int i=0; i<n; i++){
            vector<vector<int>> dp(n, vector<int> (n,-10));
            min_path = min(min_path, getMinPathValue(n-1, i, n, matrix, dp));
        }
        return min_path;
    }
};

// tabulated
// tc -> O(n*n*n), sc -> O(n*n)
class Solution {
public:
    int getMinPathValue(int row, int col, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(col<0 || col>=n) return INT_MAX;
        if(row==0)  return matrix[row][col];
        if(dp[row][col]!=-10)    return dp[row][col];
        int up = getMinPathValue(row-1, col, n, matrix, dp);
        int left = getMinPathValue(row-1, col-1, n, matrix, dp);
        int right = getMinPathValue(row-1, col+1, n, matrix, dp);
        return dp[row][col] = min({up, right, left}) + matrix[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int min_path = INT_MAX;
        for(int i=0; i<n; i++){
            vector<vector<int>> dp(n, vector<int> (n,0));
            for(int i=0; i<n; i++)  dp[0][i] = matrix[0][i];
            for(int i=1; i<n; i++){
                for(int j=0; j<n; j++){
                    int left = INT_MAX, up = INT_MAX, right = INT_MAX;
                    if(j>0) left = dp[i-1][j-1];
                    up = dp[i-1][j];
                    if(j<n-1)   right = dp[i-1][j+1];
                    dp[i][j] = min({up, right, left}) + matrix[i][j];
                }
            }
            for(int i=0; i<n; i++)
                min_path = min(min_path, dp[n-1][i]);
        }
        return min_path;
    }
};


// space optmized
// tc -> O(n*n*n), sc -> O(2*n)
class Solution {
public:
    int getMinPathValue(int row, int col, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(col<0 || col>=n) return INT_MAX;
        if(row==0)  return matrix[row][col];
        if(dp[row][col]!=-10)    return dp[row][col];
        int up = getMinPathValue(row-1, col, n, matrix, dp);
        int left = getMinPathValue(row-1, col-1, n, matrix, dp);
        int right = getMinPathValue(row-1, col+1, n, matrix, dp);
        return dp[row][col] = min({up, right, left}) + matrix[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int min_path = INT_MAX;
        for(int i=0; i<n; i++){
            vector<int> prev (n,0);
            for(int i=0; i<n; i++)  prev[i] = matrix[0][i];
            for(int i=1; i<n; i++){
                vector<int> curr(n,0);
                for(int j=0; j<n; j++){
                    int left = INT_MAX, up = INT_MAX, right = INT_MAX;
                    if(j>0) left = prev[j-1];
                    up = prev[j];
                    if(j<n-1)   right = prev[j+1];
                    curr[j] = min({up, right, left}) + matrix[i][j];
                }
                prev = curr;
            }
            for(int i=0; i<n; i++)
                min_path = min(min_path, prev[i]);
        }
        return min_path;
    }
};