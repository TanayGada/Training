/*
link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s

Row with max 1s
Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

We can solve it using binary search by finding the upperbound/lowerbound to get the first instance of 1 in every rows.
We know number of ones in an arr is n-1stInstance
the solution is O(nlogm)

A better solution to solve in O(n+m) time
We start from right-top corner and
Go left if we get a 1
Go down if we get a 0
Every time we get a 1, we save the row number
*/

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int row = 0;
        int col = arr[0].size()-1;
        int ans = -1;
        while(row<arr.size() && col>=0){
            if(arr[row][col]==1){
                col--;
                ans = row;
            }
            else{
                row++;
            }
        }
        return ans;
    }
};