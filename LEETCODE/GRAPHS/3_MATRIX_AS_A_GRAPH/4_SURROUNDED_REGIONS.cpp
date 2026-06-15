/*
https://leetcode.com/problems/surrounded-regions/description/

Surrounded Regions
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

All regions of 'o' which have atleast one 'o' at boundary of matrix cannot be surrounded by 'x' and hence cant be fully converted to 'x'
We initialize an ansMatrix with 'x'
We run a dfs for all 'o' on the boundary of originalMatrix and update the ansMatrix for these 'o's

dfs will run for n*m*4 times for worst case
tc => O(2n+2m + n*m*4)
sc => O(n*m + n*m) =>dfs, ansMatrix
*/

class Solution {
public:
    void convert(int x, int y, vector<vector<char>>& board, vector<vector<char>>& newBoard){
        int n = board.size(), m = board[0].size();
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        newBoard[x][y] = 'O';
        for(int i=0;i<4;i++){
            int newX = x + delRow[i];
            int newY = y + delCol[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m && board[newX][newY]=='O' && newBoard[newX][newY]=='X'){
                convert(newX, newY, board, newBoard);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<char>> newBoard(n, vector<char>(m,'X'));
        // Process the first and last row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && newBoard[0][j] == 'X') {
                convert(0, j, board, newBoard);
            }
            if (board[n-1][j] == 'O' && newBoard[n-1][j] == 'X') {
                convert(n-1, j, board, newBoard);
            }
        }

        // Process the first and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && newBoard[i][0] == 'X') {
                convert(i, 0, board, newBoard);
            }
            if (board[i][m-1] == 'O' && newBoard[i][m-1] == 'X') {
                convert(i, m-1, board, newBoard);
            }
        }
        board = newBoard;
    }
};


// we can get the 'O's which will stay intact by using DFS from boundary
// make rest all as 'X'

// tc -> dfs (4*n*m) + boundary O(n) + O(m), final ans (n*m)
// sc -> n*m (visited) + n*m (dfs)

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board){
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = board.size();
        int n = board[0].size();
        visited[row][col] = true;
        for(int i=0; i<4; i++){
            int x = row + dir[i][0];
            int y = col + dir[i][1];
            if(x<0 || x>=m || y<0 || y>=n)  continue;
            if(board[x][y]=='O' && !visited[x][y])    dfs(x, y, visited, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, false));
        for(int i=0; i<m; i++){
            if(board[i][0]=='O' && !visited[i][0]) dfs(i, 0, visited, board);
            if(board[i][n-1]=='O' && !visited[i][n-1]) dfs(i, n-1, visited, board);
        }
        for(int i=0; i<n; i++){
            if(board[0][i]=='O' && !visited[0][i]) dfs(0, i, visited, board);
            if(board[m-1][i]=='O' && !visited[m-1][i]) dfs(m-1, i, visited, board);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j])  board[i][j] = 'X';
            }
        }
    }
};