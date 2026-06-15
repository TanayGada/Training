// dp[i] -> length of LIS ending at index i
// cnt[i] -> no of LIS ending at index i
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int maxi = 0;
        for(int curr = 0; curr<n; curr++){
            for(int prev = 0; prev<curr; prev++){
                if(nums[curr]>nums[prev]){
                    if(dp[curr]<dp[prev]+1){
                        dp[curr] = (dp[prev]+1);
                        cnt[curr] = cnt[prev];
                    }
                    else if(dp[curr]==dp[prev]+1){
                        cnt[curr] += cnt[prev];
                    }
                }
            }
            maxi = max(maxi, dp[curr]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp[i]==maxi) ans += cnt[i];
        }
        return ans;
    }
};

// nums -> 1 3 5 4 7
// dp.  -> 1 2 1 1 1 
// cnt. -> 1 1 1 1 1