/*
link: https://leetcode.com/problems/split-array-largest-sum/description/

Split Array Largest Sum
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

similar to book allocation problem
We can check for each largestSubArrSumVal from max_element(arr) to sumOfAllEle(arr)
The first largestSubArrSumVal which satisfies the below condition is the ans.
for every largestSubArrSumVal, we check if there are less than or equal to k subArrays with sum <= largestSubArrSumVal.
We can use Binary Search to eliminate the above for loop
*/

class Solution {

private:
    bool isPossible(vector<int>& nums, int k, int maxSubArrSum){
        int sum = 0;
        int subArr = 1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=maxSubArrSum){
                sum += nums[i];
            }
            else{
                sum = nums[i];
                subArr++;
            }
        }
        if(subArr<=k)   return true;
        return false;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for(int i=0;i<nums.size();i++)  high +=nums[i];
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(nums, k, mid)){
                high = mid-1;
                ans = min(ans, mid);
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};  
