/*
https://leetcode.com/problems/search-insert-position/description/

Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Similar to Upper Bound
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low =0, high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)>>1;
            if(nums[mid]>=target){
                ans = mid;
                     high = mid-1;

            }
            else{
                           low = mid+1;
            }
        }
        return ans;
    }
};