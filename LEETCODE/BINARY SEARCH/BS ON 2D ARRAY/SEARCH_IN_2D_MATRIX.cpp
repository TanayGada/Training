/*
link: https://leetcode.com/problems/search-a-2d-matrix/description/

Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

We know all elements are sorted in a row and last ele of a row is less than first ele of next row
we can consider matrix as an array of size nxm
So we use Binary Search as it is a sorted array
We get rowInd and colInd using mod and div operator
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = rows*cols - 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int row = mid/cols;
            int col = mid%cols;
            if(matrix[row][col]==target)    return true;
            if(matrix[row][col]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};