// link: https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// LIS from start and end
// if LIS[i] = 1, it is not a valid peak point for bitonic sequence

// tc -> O(2*n*n), sc -> O(2*n)
class Solution {
  public:
    vector<int> LISFromStart(int n, vector<int>& nums){
        vector<int> dp(n, 1);
        for(int curr=0; curr<n; curr++){
            for(int prev=0; prev<curr; prev++){
                if(nums[prev]<nums[curr])   dp[curr] = max(dp[curr], dp[prev]+1);
            }
        }
        return dp;
    }
    vector<int> LISFromEnd(int n, vector<int>& nums){
        vector<int> dp(n, 1);
        for(int curr=n-1; curr>=0; curr--){
            for(int nxt=n-1; nxt>curr; nxt--){
                if(nums[nxt]<nums[curr])   dp[curr] = max(dp[curr], dp[nxt]+1);
            }
        }
        return dp;
    }
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> start = LISFromStart(n, nums);
        vector<int> end = LISFromEnd(n, nums);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(start[i]!=1 && end[i]!=1)
            ans = max(ans, start[i]+end[i]);
        }
        return ans==0?0 : ans-1;
    }
};
