// link: https://leetcode.com/problems/house-robber-ii/description/
// similar to house robber 1
// 2 cases, 1st and last cannot occur togther
class Solution {
public:
    int func(vector<int>& nums){
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        int curr = prev1;
        vector<int> dp(n, 0);
        int neg = 0;
        for(int i=1; i<n; i++){
            int pick = nums[i]+(i==1?neg:prev2);
            int not_pick = prev1;
            curr = max(pick, not_pick);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums){
        if(nums.size()==1)  return nums[0];
        vector<int> nums1;
        vector<int> nums2;
        for(int i=0; i<nums.size(); i++){
            if(i!=0)    nums1.push_back(nums[i]);
            if(i!=nums.size()-1)    nums2.push_back(nums[i]);
        }  
        return max(func(nums1), func(nums2));
    }
};