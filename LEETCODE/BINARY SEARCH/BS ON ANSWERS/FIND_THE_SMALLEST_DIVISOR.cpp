/*
link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

Find the Smallest Divisor Given a Threshold
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
The test cases are generated so that there will be an answer.

We check for all divisor, we get from binary search whether is satisfying required condition or not. 
*/


class Solution {
public:
    bool isPossible(int divisor, vector<int>& nums, int threshold){
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += ((nums[i]+divisor-1)/divisor);
            if(sum>threshold)    return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(mid, nums, threshold)){
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