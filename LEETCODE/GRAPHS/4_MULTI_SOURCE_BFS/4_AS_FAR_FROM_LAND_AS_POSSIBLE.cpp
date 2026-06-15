// https://leetcode.com/problems/as-far-from-land-as-possible/

// we need distance of water cell from land cell is maximized
// we calculate distance of nearest land cell for each water cell, get the maximum among those

// tc -> n*n 
// sc -> n*n + n*n
class Solution {

    int multisourceBfs(queue<vector<int>>& qt, vector<vector<int>>& grid, vector<vector<int>>& visited){
        int n = grid.size();
        int maxDist = -1;
        int dist = 1;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!qt.empty()){ 
            int sz = qt.size();
            while(sz--){
                int x = qt.front()[0];
                int y = qt.front()[1];
                maxDist = qt.front()[2];
                qt.pop();
                for(int i=0; i<4; i++){
                    int xx = dir[i][0] + x;
                    int yy = dir[i][1] + y;
                    if(xx>=0 && xx<n && yy>=0 && yy<n && !visited[xx][yy] && grid[xx][yy]==0){
                        visited[xx][yy] = true;
                        qt.push({xx, yy, dist});
                    }
                }
            }
            dist++;
        }
        return maxDist;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int> (n, false));
        queue<vector<int>> qt;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    visited[i][j] = true;
                    qt.push({i, j, 0});
                }  
            }
        }
        if(qt.size()==n*n || qt.size()==0)    return -1;
        return multisourceBfs(qt, grid, visited);
        
    }
};