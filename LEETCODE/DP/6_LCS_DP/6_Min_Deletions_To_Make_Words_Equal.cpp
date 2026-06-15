// link: https://leetcode.com/problems/delete-operation-for-two-strings/submissions/1895224052/
// after deletion, the words become equal and is equal to LCS
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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return n+m-2*LCS(word1, word2, n, m);
    }
};