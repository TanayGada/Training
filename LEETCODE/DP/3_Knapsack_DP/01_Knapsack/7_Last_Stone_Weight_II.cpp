// similar to variant 1 of 3_Partition_Array_To_Minimize_Sum

// tabulated
// tc -> O(n*sum), sc -> O(n*sum)
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // code here
        int sum = 0;
        for(int i : stones)    sum+=i;
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        if(stones[0]<=sum) dp[0][stones[0]] = true;
        for(int ind=1; ind<n; ind++){
            for(int target=1; target<=sum; target++){
                bool pick = false;
                if(target>=stones[ind])  pick = dp[ind-1][target-stones[ind]];
                bool not_pick = dp[ind-1][target];
                dp[ind][target] = (pick|not_pick);
            }
        }
        int mini = INT_MAX;
        for(int s1=0; s1<=sum/2; s1++){
            if(dp[n-1][s1]){
                mini = min(mini, sum-2*s1);
            }
        }
        return mini;
    }
};