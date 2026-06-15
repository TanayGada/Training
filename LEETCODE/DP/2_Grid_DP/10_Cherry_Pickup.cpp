// we move alice and bob together, but both have rows same at any time
// we have 3 states, common_row, col_alice, col_bob
// there can be 9 possibilities of next state, alice goes left diag, bob goes (left diag, down, right diag), and so on

// memoized
// state func(i, j1, j2) is max_no_of_cherry from (i, j1, j2) to any cols in last row (rows-1)
// tc -> O(n*m*m*9), sc -> O(n*m*m) + O(n)
class Solution {
public:
    int func(int i, int j1, int j2, int rows, int cols, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(j1>=cols || j1<0 || j2>=cols || j2<0) return -1e8;
        if(i == rows-1){
            if(j1==j2)  return grid[i][j1];
            else    return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)   return dp[i][j1][j2];
        int maxi = INT_MIN;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                int val = 0;
                if(j1==j2) val += grid[i][j1];
                else val += grid[i][j1] + grid[i][j2];
                val += func(i+1, j1+dj1, j2+dj2, rows, cols, grid, dp);
                maxi = max(maxi, val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>> (cols, vector<int> (cols, -1)));
        return func(0, 0, cols-1, rows, cols, grid, dp);
        
    }
};

// tabulation
// tc -> O(n*m*m*9), sc -> O(n*m*m)
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>> (cols, vector<int> (cols, 0)));
        for(int j1=0; j1<cols; j1++){
            for(int j2=0; j2<cols; j2++){
                if(j1==j2)    dp[rows-1][j1][j2] = grid[rows-1][j2];
                else dp[rows-1][j1][j2] = grid[rows-1][j1] + grid[rows-1][j2];
            }
        }
        
        for(int i=rows-2; i>=0; i--){
            for(int j1=0; j1<cols; j1++){
                for(int j2=0; j2<cols; j2++){
                    int maxi = INT_MIN;
                    for(int dj1=-1; dj1<=1; dj1++){
                        for(int dj2=-1; dj2<=1; dj2++){
                            int val = 0;
                            if(j1==j2) val += grid[i][j1];
                            else val += grid[i][j1] + grid[i][j2];
                            if(j1+dj1 >=0 && j1+dj1<cols && j2+dj2>=0 && j2+dj2<cols)
                                val += dp[i+1][j1+dj1][j2+dj2];
                            else val += -1e8;
                            maxi = max(maxi, val);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][cols-1];
        
    }
};

// space optmized
// sc -> O(m*m)
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> prev(cols, vector<int> (cols, 0));
        for(int j1=0; j1<cols; j1++){
            for(int j2=0; j2<cols; j2++){
                if(j1==j2)    prev[j1][j2] = grid[rows-1][j2];
                else prev[j1][j2] = grid[rows-1][j1] + grid[rows-1][j2];
            }
        }
        
        for(int i=rows-2; i>=0; i--){
            vector<vector<int>> curr(cols, vector<int> (cols, 0));
            for(int j1=0; j1<cols; j1++){
                for(int j2=0; j2<cols; j2++){
                    int maxi = INT_MIN;
                    for(int dj1=-1; dj1<=1; dj1++){
                        for(int dj2=-1; dj2<=1; dj2++){
                            int val = 0;
                            if(j1==j2) val += grid[i][j1];
                            else val += grid[i][j1] + grid[i][j2];
                            if(j1+dj1 >=0 && j1+dj1<cols && j2+dj2>=0 && j2+dj2<cols)
                                val += prev[j1+dj1][j2+dj2];
                            else val += -1e8;
                            maxi = max(maxi, val);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            prev = curr;
        }
        return prev[0][cols-1];
        
    }
};