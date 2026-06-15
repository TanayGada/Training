/*
link: https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

Find Kth Rotation
Given a increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Intuition here is the number of times the array is rotated is same as the index of the smallest element of the array.
We find index of the smallest element of the array

*/


class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = INT_MAX, ind;
        while(low<=high){
            int mid = (low+high)>>1;
            if(arr[low]<arr[high]){
                if(ans>arr[low]){
                    ind = low;
                }
                break;    
            }
            if(arr[low]<=arr[mid]){
                if(ans>arr[low]){
                    ans = arr[low];
                    ind = low;
                }
                low = mid+1;
            }
            else{
                if(ans>arr[mid]){
                    ans = arr[mid];
                    ind = mid;
                }
                high = mid-1;
            }
        }
        return ind;
    }
};