/*
link: https://leetcode.com/problems/search-a-2d-matrix-ii/description/

Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

The approach is similar to Row With Max Number Of 1s
We stand at right-top element in matrix and see that
All elements towards left are smaller and elements below are larger
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size()-1, cols = matrix[0].size()-1;
        int row = 0, col = cols;
        while(row<=rows && col>=0){
            if(matrix[row][col]==target)    return true;
            if(matrix[row][col]>target){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};