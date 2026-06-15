// https://leetcode.com/problems/number-of-islands/description/

// count connected components
// either bfs or dfs


// tc -> O(N*N)
// sc -> O(n*n) + O(n*n)
class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid, int m, int n){
        if(i<0 || i>=m) return;
        if(j<0 || j>=n) return;
        if(grid[i][j]=='0' || visited[i][j]) return;
        visited[i][j] = true;
        dfs(i+1, j, visited, grid, m, n);
        dfs(i-1, j, visited, grid, m, n);
        dfs(i, j+1, visited, grid, m, n);
        dfs(i, j-1, visited, grid, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(i, j, visited, grid, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};