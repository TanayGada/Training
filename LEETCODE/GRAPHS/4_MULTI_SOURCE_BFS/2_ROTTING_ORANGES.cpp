/*
https://leetcode.com/problems/rotting-oranges/description/

This is a multi-source BFS problem. All initially rotten oranges act as sources, 
and we simulate the spread level by level, where each level corresponds to one minute. 
I’ll push all rotten oranges into a queue, 
then for each step, rot adjacent fresh oranges and decrement the fresh count. 
If at the end fresh oranges remain, return -1, otherwise return the time taken


sc => O(n*m)
tc => O(n*m) + O(4*n*m) 
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        vector<vector<bool>> isRotten(n, vector<bool>(m,false));
        queue<pair<int,pair<int,int>>> qt;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2){
                    qt.push({0,{i,j}});
                    isRotten[i][j] = true;
                }
            }
        }
        vector<int> delRow = {0,-1,0,1};
        vector<int> delCol = {-1,0,1,0};
        int ans = 0;
        while(!qt.empty()){
            int x = qt.front().second.first;
            int y = qt.front().second.second;
            int time = qt.front().first;
            qt.pop();
            ans = time;
            for(int i=0;i<delRow.size();i++){
                int newX = x+delRow[i];
                int newY = y+delCol[i];
                if(newX>=0 && newX<n && newY>=0 && newY<m && !isRotten[newX][newY] && grid[newX][newY]==1){
                    qt.push({time+1,{newX,newY}});
                    isRotten[newX][newY] = true;
                    fresh--;
                }
            }
        }
        
        return fresh ? -1 : ans;
    }
};