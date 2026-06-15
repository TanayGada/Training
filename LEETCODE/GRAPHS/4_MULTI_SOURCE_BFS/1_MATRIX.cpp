/*
https://leetcode.com/problems/01-matrix/description/

01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

For every cell, we need the shortest distance to a 0. Instead of running BFS from each 1 (which would be expensive), 
we reverse the thinking and run a multi-source BFS starting from all 0s simultaneously.

distance of the nearest 0 for '0' cell -> 0
distance of the nearest 0 from '1' cell -> distance of the nearest 1 from '0' cell

I treat all 0s as starting points and push them into a queue with distance 0. 
Then I perform BFS and expand to neighboring cells. Whenever I visit a cell for the first time, 
I assign its distance as current distance + 1

sc => O(n*m) + O(n*m) + (n*m) =>queue,visited,ansMatrix
tc => O((n*m) + (4*(n*m))
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> minDistance(m, vector<int>(n,0));
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> qt;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    qt.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        while(!qt.empty()){
            int x = qt.front().first.first;
            int y = qt.front().first.second;
            int steps = qt.front().second;
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};
            qt.pop();
            for(int i=0;i<4;i++){
                int newX = delRow[i] + x;
                int newY = delCol[i] + y;
                if(newX<m && newX>=0 && newY>=0 && newY<n && !visited[newX][newY]){
                    visited[newX][newY] = true;
                    minDistance[newX][newY] = steps+1;
                    qt.push({{newX,newY},steps+1});
                }
            }
        }
        return minDistance;
    }
};




// multi source bfs from each cell having 0
// the moment a cell reaches 1, mark steps as ans for that 1
class Solution {
    vector<vector<int>> bfs(queue<vector<int>>& qt, vector<vector<int>>& mat, vector<vector<int>>& visited){
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m , vector<int> (n, 0));
        int dist = 1;
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!qt.empty()){
            int sz = qt.size();
            while(sz--){
                int x = qt.front()[0];
                int y = qt.front()[1];
                ans[x][y] = qt.front()[2];
                qt.pop();
                for(int i=0; i<4; i++){
                    int xx = x + dir[i][0];
                    int yy = y + dir[i][1];
                    if(xx>=0 && xx<m && yy>=0 && yy<n && !visited[xx][yy]){
                        qt.push({xx, yy, dist});
                        visited[xx][yy] = true;
                    }
                }
            }
            dist++;
        }
        return ans;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m, vector<int> (n, false));
        queue<vector<int>> qt;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    qt.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        return bfs(qt, mat, visited);
    }
};