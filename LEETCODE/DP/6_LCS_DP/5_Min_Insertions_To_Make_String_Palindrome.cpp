// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/1895220029/
// if length of palindromic subseq is x, and length of string is n,
// to make the string palindrome, we need n-x insertions

// tc -> O(n*n), sc -> O(n*n)
class Solution {
public:
    int LCS(string& s1, string& s2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int ind1 = 1; ind1<=n; ind1++){
            for(int ind2 = 1; ind2<=m; ind2++){
                if(s1[ind1-1]==s2[ind2-1])  dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        return dp[n][m];
    }
    int minInsertions(string s) {
        int n = s.size();
        string p = s;
        reverse(p.begin(), p.end());
        return n-LCS(s, p, n, n);
    }
};