/*
link: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix


Median in a row-wise sorted Matrix
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

if r and c are always odd, there will be r*c elements i.e. odd elements,
median element would be greater than "totalElements/2" elements
We can run a binary search from low = min_element(matrix) and high = max_element(matrix)
for every mid, we check if is it greater than "totalElements/2" elements or not
if it is greater we eliminate right half else eliminate the left half
*/

class Solution{   
private:
    int getEleSmallThanMid(vector<vector<int>> &matrix, int mid, int R, int C){
        int eleSmallThanMid = 0;
        for(int i=0;i<R;i++){
            eleSmallThanMid += (upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
        }
        return eleSmallThanMid;
    }
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here          
        int low = 0, high = 0;
        for(int i=0;i<R;i++)    low = min(low,matrix[i][0]);
        for(int i=0;i<R;i++)  high = max(high, matrix[i][C-1]);
        int totalEle = R*C-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int eleSmallThanMid = getEleSmallThanMid(matrix, mid, R, C);
            if(eleSmallThanMid>totalEle/2)  {
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};