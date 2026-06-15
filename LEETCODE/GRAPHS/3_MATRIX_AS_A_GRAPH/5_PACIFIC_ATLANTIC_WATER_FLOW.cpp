// link: https://leetcode.com/problems/pacific-atlantic-water-flow/description/




// Run DFS/BFS from both ocean boundaries using reverse flow (next height >= current).
// Mark reachable cells for each ocean.
// Cells reachable from both are the answer.

// tc -> 2*((n+m)*(n*m))
// sc -> 2*(n*m) + (n*m) -> 2xvisited + 1xans
class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& heights){
        int m = heights.size();
        int n = heights[0].size();
        visited[row][col] = true;
        vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i=0; i<4; i++){
            int x = row + dir[i][0];
            int y = col + dir[i][1];
            if(x<0 || x>=m || y<0 || y>=n)  continue;
            if(!visited[x][y] && heights[x][y]>=heights[row][col]) 
                dfs(x, y, visited, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> pacific;
        vector<vector<int>> visitedPacific(m, vector<int> (n, false));
        for(int i=0;i<m; i++){
            if(!visitedPacific[i][0])
                dfs(i, 0, visitedPacific, heights);
        }
        for(int i=0;i<n; i++){
            if(!visitedPacific[0][i])
                dfs(0, i, visitedPacific, heights);
        }

        vector<vector<int>> atlantic;
        vector<vector<int>> visitedAtlantic(m, vector<int> (n, false));
        for(int i=0;i<m; i++){
            if(!visitedAtlantic[i][n-1])
                dfs(i, n-1, visitedAtlantic, heights);
        }
        for(int i=0;i<n; i++){
            if(!visitedAtlantic[m-1][i])
                dfs(m-1, i, visitedAtlantic, heights);
        }

        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visitedAtlantic[i][j] && visitedAtlantic[i][j]==visitedPacific[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};