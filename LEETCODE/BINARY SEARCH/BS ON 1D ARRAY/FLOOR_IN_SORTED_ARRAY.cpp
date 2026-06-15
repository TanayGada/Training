/*
link: https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array

FLOOR IN A SORTED ARRAY OR LOWER BOUND
Given a sorted array arr[] of size n without duplicates, and given a value x. Floor of x is defined as the largest element k in arr[] such that k is smaller than or equal to x. Find the index of k(0-based indexing).
*/

class Solution {
  public:
    int findFloor(vector<long long> &arr, long long n, long long x) {
        int low = 0, high = n-1;
        long long k = -1;
        while(low<=high){
            long long mid = low+(high-low)/1;
            if(arr[mid]>x){
                high = mid-1;
            }
            else if(arr[mid]<=x){
                k = mid;
                low = mid+1;
            }
        }   
        return k;
    }
};