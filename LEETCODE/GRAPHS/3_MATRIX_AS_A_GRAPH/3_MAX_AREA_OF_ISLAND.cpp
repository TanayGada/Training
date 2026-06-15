// https://leetcode.com/problems/max-area-of-island/


// area of each connected components, get max among them
// tc -> n*m*4 
// sc -> n*m + n*m
class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = true;
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int area = 1;
        for(int k=0; k<4; k++){
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y] && !visited[x][y]){
                area += dfs(x, y, visited, grid);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> visited(m, vector<int> (n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    maxArea = max(maxArea, dfs(i, j, visited, grid));
                }
            }
        }
        return maxArea;
    }
};