/*
link: 
https://leetcode.com/problems/find-peak-element/description/

Find Peak Element
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.

if arr[mid-1]< arr[mid] < arr[mid+1] => means peak is at right
if arr[mid-1] > arr[mid] > arr[mid+1] => means peak is at left
if arr[mid-1]< arr[mid] > arr[mid+1] => means mid is peak 
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)  return 0;
        if(nums[0]>nums[1])  return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2])  return nums.size()-1;
        int high = nums.size()-2;
        int low = 1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])  return mid;
            if(nums[mid]>nums[mid-1])   low = mid+1;
            else if(nums[mid]<nums[mid-1])  high = mid-1;
        }     
        return 90;
    }
};

