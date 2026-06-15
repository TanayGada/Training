// variant 1: non negative numbers, and partition into 2 equal/different size subsets
// link: https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
// use subset sum logic, f(ind, target) = whether possible to achieve target through subsets till index ind
// we have dp[n-1][target] = whether a target is possible by taking elements from 0 to n-1
// we need abs((target-s1)-s1) to be minimum


// tabulated
// tc -> O(n*sum), sc ->O(n*sum)
int minSubsetSumDifference(vector<int>& arr, int n){
    // code here
    int sum = 0;
    for(int i : arr)    sum+=i;
    vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    if(arr[0]<=sum) dp[0][arr[0]] = true;
    for(int ind=1; ind<n; ind++){
        for(int target=1; target<=sum; target++){
            bool pick = false;
            if(target>=arr[ind])  pick = dp[ind-1][target-arr[ind]];
            bool not_pick = dp[ind-1][target];
            dp[ind][target] = (pick|not_pick);
        }
    }
    int mini = INT_MAX;
    for(int s1=0; s1<=sum/2; s1++){
        if(dp[n-1][s1]){
            mini = min(mini, abs((sum-s1)-s1));
        }
    }
	return mini;
}


// variant 2: there are negative numbers, and we need to partition into 2 equal size subsets
// link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
// dp fails, as the sum can go negative and we cant represent them, constraints are also high
// meet in the middle concept