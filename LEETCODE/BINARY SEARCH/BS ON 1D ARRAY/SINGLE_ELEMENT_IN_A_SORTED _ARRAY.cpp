/*
link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

If array contains all elements twice and in sorted array
if ind is odd then arr[ind]==arr[ind-1]
else if ind is even then arr[ind]==arr[ind+1]
so if we get any of the above 2 conditions correct, means all elements in the left part contains exactly 1 copy, so we search in right half
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low =1;
        int high = n-2;
        if(n==1)    return nums[0];
        if(nums[0]!=nums[1])    return nums[0];
        if(nums[n-1]!= nums[n-2])   return nums[n-1];
        
        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])    return nums[mid];
            if((mid&1)){
                if(nums[mid]==nums[mid-1])  low = mid+1;
                else high = mid-1; 
            }
            else{
                if(nums[mid]==nums[mid+1])  low = mid+1;
                else high = mid-1; 
            }
        }
        return -1;
    }
};