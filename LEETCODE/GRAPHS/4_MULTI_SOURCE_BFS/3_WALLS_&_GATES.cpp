// https://neetcode.io/problems/islands-and-treasure/history?submissionIndex=0



// tc -> m*n + m*n*4
// sc -> n*m + n*m
class Solution {
public:
    void multisourceBFS(vector<vector<int>>& grid, queue<vector<int>>& qt, vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        int dist = 1;
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!qt.empty()){
            int sz = qt.size();
            while(sz--){
                int x = qt.front()[0];
                int y = qt.front()[1];
                grid[x][y] = qt.front()[2];
                qt.pop();
                for(int i=0; i<4; i++){
                    int xx = x + dir[i][0];
                    int yy = y + dir[i][1];
                    if(xx>=0 && xx<m && yy>=0 && yy<n && !visited[xx][yy] && grid[xx][yy]==INT_MAX){
                        visited[xx][yy] = true;
                        qt.push({xx, yy, dist});
                    }
                }
            }
            dist++;
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, false));
        queue<vector<int>> qt;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    visited[i][j] = true;
                    qt.push({i, j, 0});
                }
            }
        }
        multisourceBFS(grid, qt, visited);
    }
};
