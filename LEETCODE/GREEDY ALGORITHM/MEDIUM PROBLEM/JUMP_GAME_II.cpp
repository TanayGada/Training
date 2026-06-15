/*
https://leetcode.com/problems/jump-game-ii/description/

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

*/

//recursive solution => O(n^n) and space => O(n)
class Solution {
public:
    int getMinimumJumps(int ind, int jump, vector<int>& nums){
        if(ind>=(nums.size()-1))    return jump;
        int mini = INT_MAX;
        for(int i=1;i<=nums[ind];i++){
            mini = min(mini, getMinimumJumps(ind+i,jump+1,nums));
        }
        return mini;
    }

    int jump(vector<int>& nums) {
        return getMinimumJumps(0, 0, nums);
    }
};

//memoization => O(n^2) and space=> O(n*n)
class Solution {
public:
    int getMinimumJumps(int ind, int jump, vector<int>& nums, vector<vector<int>> & dp){
        if(ind>=(nums.size()-1))    return jump;
        if(dp[ind][jump]!=-1)   return dp[ind][jump];
        int mini = INT_MAX;
        for(int i=1;i<=nums[ind];i++){
            mini = min(mini, getMinimumJumps(ind+i,jump+1,nums,dp));
        }
        return dp[ind][jump] = mini;
    }

    int jump(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return getMinimumJumps(0, 0, nums,dp);
    }
};

// can do tabulation

// another approach we can use is carry ranges and for each range, we increment jump by 1
// and the new range will have newLeft = oldRight+1 and newRight = maxRange
// maxRange is max(maxRange,i+nums[i]) for left<=i<=right

class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        int maxRange = 0, jumps=0;
        while(right<n-1){
            for(int i=left;i<=right;i++){
                maxRange = max(maxRange, i+nums[i]);
            }
            left = right+1;
            jumps++;
            right = maxRange;
        }
        return jumps;
    }
};

