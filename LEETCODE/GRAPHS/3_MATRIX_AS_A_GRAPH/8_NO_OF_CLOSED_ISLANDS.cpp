// https://leetcode.com/problems/number-of-closed-islands/
// closed islands are islands which donot have land at border of grid
// we exlcude islands having cell(land) connecting the border

// tc -> n*n*4
// sc -> n*n + n*n
class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        visited[i][j] = true;
        int m = grid.size();
        int n = grid[0].size();
        bool border = false;
        if(i==0 || i==m-1 || j==0 || j==n-1) border = true;
        queue<pair<int, int>> qt;
        qt.push({i, j});
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!qt.empty()){
            int sz = qt.size();
            while(sz--){
                int x = qt.front().first;
                int y = qt.front().second;
                qt.pop();
                if(x==0 || x==m-1 || y==0 || y==n-1) border = true;
                for(int i=0; i<4; i++){
                    int xx = x+dir[i][0];
                    int yy = y+dir[i][1];
                    if(xx>=0 && xx<m && yy>=0 && yy<n && !visited[xx][yy] && grid[xx][yy]==0){
                        qt.push({xx, yy});
                        visited[xx][yy] = true;
                    }
                }
            }
        }
        return border?0:1;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    cnt += bfs(i, j, visited, grid);
                }
            }
        }
        return cnt;
    }
};