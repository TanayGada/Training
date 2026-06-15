
// from all water cells, do bfs simultaneously to reach all land cells, 
// while traversal, if the enw cell is land, store the current height + 1, as the height of the new cell

// tc -> n*m
// sc -> n*m + n*m + n*m
class Solution {
public:
    vector<vector<int>> multiBfs(queue<vector<int>>& qt, vector<vector<int>>& isWater, vector<vector<int>>& visited){
        int m = isWater.size();
        int n = isWater[0].size();
        int maxHeight = 0;
        vector<vector<int>> heightMat(m, vector<int> (n, 0));
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!qt.empty()){
            int sz = qt.size();
            while(sz--){
                int i = qt.front()[0];
                int j = qt.front()[1];
                int height = qt.front()[2];
                qt.pop();
                heightMat[i][j] = height;
                for(int k=0; k<4; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && !isWater[x][y]){
                        qt.push({x, y, height+1});
                        visited[x][y] = true;
                    }
                }
            }
        }
        return heightMat;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> visited(m, vector<int> (n, false));
        queue<vector<int>> qt;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]){
                    qt.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        return multiBfs(qt, isWater, visited);
    }
};