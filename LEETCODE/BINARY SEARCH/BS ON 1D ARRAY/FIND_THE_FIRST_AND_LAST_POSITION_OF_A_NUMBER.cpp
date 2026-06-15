/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Find First and Last Position of Element in Sorted Array

lowerBound, upperBound-1
*/




class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        int l = lb - nums.begin();
        int u = ub - nums.begin();
        
        if (lb == nums.end() || nums[l] != target) return {-1, -1};
        
        return {l, u - 1};
    }
};
