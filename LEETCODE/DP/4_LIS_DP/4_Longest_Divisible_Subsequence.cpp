// similar to printing LIS, diff is condition 
// for a sorted array, if nums[i+1]%nums[i]==0, and nums[i]%nums[i-1]==0, nums[i+1]%nums[i-1]==0
// tabulated
// tc -> O(n*n), sc -> O(2*n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        sort(nums.begin(), nums.end());
        int maxi = 0;
        int lastIndex = 0;
        for(int curr = 0; curr<n; curr++){
            hash[curr] = curr;
            for(int prev=0; prev<curr; prev++){
                if(nums[curr]%nums[prev]==0){
                    if(dp[curr]<1+dp[prev]){
                        dp[curr] = 1+dp[prev];
                        hash[curr] = prev;
                    }
                }
            }
            if(dp[curr]>maxi){
                maxi = dp[curr];
                lastIndex = curr;
            }
        }
        vector<int> ans;
        while(hash[lastIndex]!=lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};