// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// start state is 0,0
// end desired state is n-1, n-1
// start bfs from start state to end state, having only 0
// we use bfs because we need shortest path 

// tc -> n*n*8
// sc -> n*n + n*n

class Solution {
public:
    int bfs(int n, vector<vector<int>>& grid){
        queue<pair<int,int>> qt;
        vector<vector<int>> visited(n, vector<int> (n, false));
        visited[0][0] = true;
        qt.push({0, 0});
        int path = 1;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,-1}, {-1,1}};
        while(!qt.empty()){
            int sz = qt.size();
            while(sz--){
                int x = qt.front().first;
                int y = qt.front().second;
                if(x==n-1 && y==n-1) return path;
                qt.pop();
                for(int i=0; i<8; i++){
                    int xx = x+dir[i][0];
                    int yy = y+dir[i][1];
                    if(xx>=0 && xx<n && yy>=0 && yy<n && !visited[xx][yy] && grid[xx][yy]==0){
                        visited[xx][yy] = true;
                        qt.push({x+dir[i][0], y+dir[i][1]});
                    }
                }
            }
            path++;
        }
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])    return -1;
        return bfs(n, grid);
    }
};