// dp[i][j] stores size of square whose left top is at index i,j
// for a square to happen at i,j, the right, bottom and diagonal element should be top left of another squares 
// size of square with top left at i,j is min(right, bottom, diagonal) + 1
// refer Maximal Square problem, only difference is we add side to ans
// memoization
// tc -> O(n*m), sc -> O(n*m) + O(n*m)
class Solution {
public:
    int func(int i, int j, int& squares, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(i>=rows || j>=cols)  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int down = func(i+1, j, squares, matrix, dp);
        int right = func(i, j+1, squares, matrix, dp);
        int diag = func(i+1, j+1, squares, matrix, dp);
        if(matrix[i][j]==1){
            int side = min({down, right, diag})+1;
            squares += side;
            return dp[i][j] = side;
        }
        return dp[i][j] = 0;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int squares = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int> (cols, -1));
        func(0, 0, squares, matrix, dp);
        return squares;
    }
};

//tabulation
// tc -> O(n*m), sc -> O(n*m)
class Solution {
public:

    int countSquares(vector<vector<int>>& matrix) {
        int squares = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows+1, vector<int> (cols+1, 0));
        for(int i = rows-1; i>=0; i--){
            for(int j=cols-1; j>=0; j--){
                int down = dp[i+1][j];
                int right = dp[i][j+1];
                int diag = dp[i+1][j+1];
                if(matrix[i][j]==1){
                    dp[i][j] = min({down, right, diag})+1;
                    squares += dp[i][j];
                }
            }
        }
        return squares;
    }
};

// space optmized
// tc -> O(n*m), sc -> O(2*m)
class Solution {
public:

    int countSquares(vector<vector<int>>& matrix) {
        int squares = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> prev(cols+1, 0);
        for(int i = rows-1; i>=0; i--){
            vector<int> curr(cols+1, 0);
            for(int j=cols-1; j>=0; j--){
                int down = prev[j];
                int right = curr[j+1];
                int diag = prev[j+1];
                if(matrix[i][j]==1){
                    curr[j] = min({down, right, diag})+1;
                    squares += curr[j];
                }
            }
            prev = curr;
        }
        return squares;
    }
};