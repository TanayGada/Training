// dp[i][j] stores size of square whose left top is at index i,j
// for a square to happen at i,j, the right, bottom and diagonal element should be top left of another squares 
// size of square with top left at i,j is min(right, bottom, diagonal) + 1

// memoization
// tc -> O(n*m), sc -> O(n*m) + O(n*m)
class Solution {
public:
    int func(int i, int j, int& max_area, vector<vector<char>>& matrix, vector<vector<int>>& dp){
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(i>=rows || j>=cols)  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int down = func(i+1, j, max_area, matrix, dp);
        int right = func(i, j+1, max_area, matrix, dp);
        int diag = func(i+1, j+1, max_area, matrix, dp);
        if(matrix[i][j]=='1'){
            int side = min({down, right, diag})+1;
            max_area = max(max_area, side*side);
            return dp[i][j] = side;
        }
        return dp[i][j] = 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int max_area = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int> (cols, -1));
        func(0, 0, max_area, matrix, dp);
        return max_area;
    }
};

//tabulation
// tc -> O(n*m), sc -> O(n*m)
class Solution {
public:

    int maximalSquare(vector<vector<char>>& matrix) {
        int max_area = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows+1, vector<int> (cols+1, 0));
        for(int i = rows-1; i>=0; i--){
            for(int j=cols-1; j>=0; j--){
                int down = dp[i+1][j];
                int right = dp[i][j+1];
                int diag = dp[i+1][j+1];
                if(matrix[i][j]=='1'){
                    dp[i][j] = min({down, right, diag})+1;
                    max_area = max(max_area, dp[i][j]*dp[i][j]);
                }
            }
        }
        return max_area;
    }
};

// space optmized
// tc -> O(n*m), sc -> O(2*m)
class Solution {
public:

    int maximalSquare(vector<vector<char>>& matrix) {
        int max_area = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> prev(cols+1, 0);
        for(int i = rows-1; i>=0; i--){
            vector<int> curr(cols+1, 0);
            for(int j=cols-1; j>=0; j--){
                int down = prev[j];
                int right = curr[j+1];
                int diag = prev[j+1];
                if(matrix[i][j]=='1'){
                    curr[j] = min({down, right, diag})+1;
                    max_area = max(max_area, curr[j]*curr[j]);
                }
            }
            prev = curr;
        }
        return max_area;
    }
};