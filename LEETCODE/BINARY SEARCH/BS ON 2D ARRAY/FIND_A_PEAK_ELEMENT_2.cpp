/*
link: 

Find a Peak Element II
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

We want to find an element in the matrix which is greater than elements above, below, right and left of it.
Brute Force can be to find the Largest Element in the whole Matrix, as it would satisfy all conditions
If we apply a binary search to select a column
and then find the peak element in that column
We get an element which is always greater than elements above and below it
We need to check its right and left
If right element is greater, we eliminate the left half and continue BS to select column
else we eliminate the right half
We need to find the local maximum element
*/

class Solution {
public:
    int getMaxElementRow(vector<vector<int>>& mat, int col){
        int max = INT_MIN, ind = -1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>max){
                max = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int low = 0, high = cols-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int maxElementRow = getMaxElementRow(mat, mid);
            int eleAtLeft = (mid-1>=0)? mat[maxElementRow][mid-1] : -1;
            int eleAtRight = (mid+1<cols)? mat[maxElementRow][mid+1] : -1;
            if(eleAtLeft<mat[maxElementRow][mid] && eleAtRight<mat[maxElementRow][mid]) return {maxElementRow, mid};
            if(eleAtLeft>mat[maxElementRow][mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};