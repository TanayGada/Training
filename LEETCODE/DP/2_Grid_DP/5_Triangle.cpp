// fixed starting point and variable ending point
// memoized
// tc -> O(n*n), sc -> O(n*n) + O(n*n)
class Solution {
public:
    int func(int i, int j, int& n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=-1)    return dp[i][j];
        int down = triangle[i][j] + func(i+1, j, n, triangle, dp);
        int down_right = triangle[i][j] + func(i+1, j+1, n, triangle, dp);
        return dp[i][j] = min(down, down_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(0, 0, n, triangle, dp);
    }
};

// tabulated
// tc -> O(n*n), sc -> O(n*n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                dp[i][j] = min(dp[i+1][j] + triangle[i][j], dp[i+1][j+1]+ triangle[i][j]);
            }
        }
        return dp[0][0];
    }
};

// space optmized
// tc -> O(n*n), sc -> O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n, 0);
        for(int i=0; i<n; i++){
            prev[i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            vector<int> curr(n, 0);
            for(int j=0; j<=i; j++){
                curr[j] = min(prev[j] + triangle[i][j], prev[j+1]+ triangle[i][j]);
            }
            prev = curr;
        }
        return prev[0];
    }
};