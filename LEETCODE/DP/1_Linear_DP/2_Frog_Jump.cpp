//link: https://www.geeksforgeeks.org/problems/geek-jump/1
//memoized
// tc -> O(n), sc -> O(n)
class Solution {
  public:
    int func(int ind, vector<int>& height, vector<int>& dp){
        if(ind==0)  return 0;
        if(ind==1)  return abs(height[1]-height[0]);
        if(dp[ind]!=-1)  return dp[ind];
        int left = abs(height[ind]-height[ind-1])+func(ind-1, height, dp);
        int right = abs(height[ind]-height[ind-2])+func(ind-2, height, dp);;
        return dp[ind] = min(left, right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        return func(n-1, height, dp);
    }
};
//tabulated
// tc -> O(n), sc -> O(n)
int minCost(vector<int>& height){
    int n = height.size();
    vector<int> dp(n,-1);
    dp[0] = 0;
    dp[1] = abs(height[0]-height[1]);
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-1] + abs(height[i]-height[i-1]), dp[i-2] + abs(height[i] - height[i-2]));
    }
    return dp[n-1];
}

// space optmized
//tc -> O(n), sc -> O(1)
int minCost(vector<int>& height){
    int n = height.size();
    int prev1 = abs(height[0]-height[1]);
    int prev2 = 0;
    int curr = 0;
    if(n==2)    return prev1;
    for(int i=2; i<n; i++){
        curr = min(prev1 + abs(height[i]-height[i-1]), prev2 + abs(height[i] - height[i-2]));
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}