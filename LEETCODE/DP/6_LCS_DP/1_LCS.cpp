// 1 pointer each for 2 strings
// if character at both pointer are equal, decrement both pointer
// else decrement either of one and take max

// tc -> O(n*n), sc -> O(n*n) + O(n+m)
class Solution {
public:
    int func(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>& dp){
        if(ind1<0 || ind2<0)    return 0;
        if(dp[ind1][ind2]!=-1)  return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])   return dp[ind1][ind2] = 1+func(ind1-1, ind2-1, s1, s2, dp);
        else return dp[ind1][ind2] = max(func(ind1-1, ind2, s1, s2, dp), func(ind1, ind2-1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return func(n1-1, n2-1, text1, text2, dp);
    }
};

// tabulated
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        // return func(n1-1, n2-1, text1, text2, dp);
        for(int ind1=1; ind1<=n1; ind1++){
            for(int ind2=1; ind2<=n2; ind2++){
                if(text1[ind1-1]==text2[ind2-1])   dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        return dp[n1][n2];
    }
};