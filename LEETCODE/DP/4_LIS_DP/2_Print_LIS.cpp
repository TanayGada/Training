// similar to tabulation version of prev problem
// store the prev index of element which was chosen to continue LIS at curr index, then backtrack to get LIS
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int>dp (n, 1);
        vector<int> hash(n);
        int maxi = 0;
        int lastIndex = 0;
        for(int curr=0; curr<n; curr++){
            hash[curr] = curr;
            for(int prev=0; prev<curr; prev++){
                if(arr[prev]<arr[curr]){
                    if(dp[curr] < 1+dp[prev]){
                        dp[curr] = dp[prev]+1;
                        hash[curr] = prev;
                    }
                }
            }
            if(maxi<dp[curr]){
                maxi = dp[curr];
                lastIndex = curr;
            }
        }
        vector<int> ans;
        while(hash[lastIndex]!=lastIndex){
            ans.push_back(arr[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(arr[lastIndex]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};