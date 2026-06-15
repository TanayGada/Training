/*
https://leetcode.com/problems/number-of-enclaves/description/

All 1s connected to boundaries cannot be considered as enclaves
So we can mark all such 1s and then traverse and get the number of notMarked 1s

We use bfs/dfs to mark all 1s connected to boundary O(n*m)
We then traverse visitedArray and originalMatrix to get the number of unmarked 1s
sc => O(n*m + n*m)  queue, visited
tc => O(n*m*4)
*/

class Solution {
private:
    void mark1s(int x, int y, vector<vector<int>>& grid, vector<vector<bool>> &visited){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> qt;
        qt.push({x,y});
        visited[x][y] = true;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!qt.empty()){
            int xc = qt.front().first;
            int yc = qt.front().second;
            qt.pop();
            for(int i=0;i<4;i++){
                int newX = xc + delRow[i];
                int newY = yc + delCol[i];
                if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1 && !visited[newX][newY]){
                    qt.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int numOfEnclaves = 0;
        vector<vector<bool>> visited(n, vector<bool> (m,false));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !visited[i][0]){
                mark1s(i, 0, grid, visited);
            }
            if(grid[i][m-1]==1 && !visited[i][m-1]){
                mark1s(i, m-1, grid, visited);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !visited[0][j]){
                mark1s(0, j, grid, visited);
            }
            if(grid[n-1][j]==1 && !visited[n-1][j]){
                mark1s(n-1, j, grid, visited);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]) numOfEnclaves++;
            }
        }
        return numOfEnclaves;
    }
};




// find connected components which donot have any cell at boundary
// we exclude connected components having a cell at boundary
// tc -> n*n*4
// sc -> n*n + n*n
class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        visited[i][j] = true;
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 1;
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
                    if(xx>=0 && xx<m && yy>=0 && yy<n && !visited[xx][yy] && grid[xx][yy]==1){
                        qt.push({xx, yy});
                        cnt++;
                        visited[xx][yy] = true;
                    }
                }
            }
        }
        return border?0:cnt;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    cnt += bfs(i, j, visited, grid);
                }
            }
        }
        return cnt;
    }
};