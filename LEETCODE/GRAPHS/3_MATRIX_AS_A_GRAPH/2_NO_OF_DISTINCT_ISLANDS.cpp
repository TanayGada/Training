/*
https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

Number of Distinct Islands
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).   

To identify distinct islands, we can consider storing the list of coordinates of that component
While storing that component, we store each coordinate wrt to the base coordinate i.e. subtract base coordinate from each coordinate
We need to make sure that a particular direction of traversal is followed through out the algorithm so that the list remains consistent

sc => O(n*m) + O(n*m) + O(n*m)
     visited    set      vec
tc => O(n*m*4) + O(n*m)
        dfs       loop

*/

class Solution {
  private:
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid, vector<pair<int,int>>& vec, int i0, int j0){
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = true;
        vec.push_back({i-i0, j-j0});
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        for(int d=0;d<4;d++){
            int x = delRow[d] + i;
            int y = delCol[d] + j;
            if(x>=0 && y>=0 && x<n && y<m && !visited[x][y] && grid[x][y]==1){
                dfs(x,y,visited,grid, vec, i0, j0);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i, j, visited, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};