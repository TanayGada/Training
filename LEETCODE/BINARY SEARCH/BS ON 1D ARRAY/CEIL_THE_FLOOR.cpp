/*
link : https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

Ceil The Floor / LOWER AND UPPER BOUND
Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].
Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].
Return an array of integers denoting the [floor, ceil]. Return -1 as the floor or ceiling value if the floor or ceiling is not present.
*/

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int low = 0, high = arr.size()-1;
        sort(arr.begin(),arr.end());
        long long ceil=-1, floor = -1;
        while(low<=high){
            long long mid = (low+high)/2;
            if(arr[mid]>x){
                ceil = arr[mid];
                high = mid-1;
            }
            else if(arr[mid]<x){
                floor = arr[mid];
                low = mid+1;
            }
            else{
                floor = arr[mid];
                ceil = arr[mid];
                return {floor, ceil};
            }
        }   
        return {floor, ceil};
    }
};