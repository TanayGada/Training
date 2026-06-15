/*
Link: https://leetcode.com/problems/jump-game/description/

Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

We check if we can reach the end by any chance
for which, we maintain an lastIndex (denoting the last most index which can be reached by jumping)
lastIndex = max(lastIndex, nums[i]+i)
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastIndex = 0;
        for(int i=0;i<nums.size();i++){
            if(lastIndex>=i ){
                lastIndex=max(nums[i]+i, lastIndex);
            }
            else break;
        }
        if(lastIndex<nums.size()-1) return false;
        return true;
    }
};
