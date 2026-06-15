// link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

// if s1[ind1] == s2[ind2], we consider this and dp[ind1-1][ind2-1] which denotes if the prev indices had same or different elements
// tc -> O(n*m), sc -> O(n*m)
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        int maxi = 0;
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=m; ind2++){
                if(s1[ind1-1]==s2[ind2-1])  dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                maxi = max(maxi, dp[ind1][ind2]);
            }
        }
        return maxi;
    }
};