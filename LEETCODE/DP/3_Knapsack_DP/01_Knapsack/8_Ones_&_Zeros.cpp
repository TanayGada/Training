// func(ind, m, n) -> max size subset upto index ind, which contain zeros<=m and ones<=n

//memoized
// tc -> O(sz*n*m), sc -> O(sz*n*m) + O(sz)
class Solution {
public:
    int getCnt(string& s, char ch){
        int cnt = 0;
        for(char c : s){
            if(c==ch)  cnt++;
        }
        return cnt;
    }
    
    int func(int ind, int zero, int one, vector<string>& strs, vector<vector<vector<int>>>& dp){
        if(ind==0){
            return (zero>=getCnt(strs[0], '0') && one>=getCnt(strs[0], '1'));
        }
        if(dp[ind][zero][one]!=-1)  return dp[ind][zero][one];
        int not_pick = func(ind-1, zero, one, strs, dp);
        int pick = 0;
        if(zero >= getCnt(strs[ind], '0') && one >= getCnt(strs[ind], '1'))
            pick = 1 + func(ind-1, zero-getCnt(strs[ind], '0'), one-getCnt(strs[ind], '1'), strs, dp);
        return dp[ind][zero][one] = max(pick, not_pick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>> (m+1, vector<int> (n+1,-1)));
        return func(sz-1, m, n, strs, dp);
    }
};

// tabulation
// tc -> O(sz*n*m), sc -> O(sz*n*m)
class Solution {
public:
    int getCnt(string& s, char ch){
        int cnt = 0;
        for(char c : s){
            if(c==ch)  cnt++;
        }
        return cnt;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>> (m+1, vector<int> (n+1,0)));
        for(int zero=0; zero<=m; zero++){
            for(int one=0; one<=n; one++){
                if(zero>=getCnt(strs[0], '0') && one>=getCnt(strs[0], '1')) dp[0][zero][one]=1;
                else dp[0][zero][one]=0;
            }
        }
        for(int ind=1; ind<sz; ind++){
            for(int zero=0; zero<=m; zero++){
                for(int one=0; one<=n; one++){
                    int not_pick = dp[ind-1][zero][one];
                    int pick = 0;
                    if(zero >= getCnt(strs[ind], '0') && one >= getCnt(strs[ind], '1'))
                        pick = 1 + dp[ind-1][zero-getCnt(strs[ind], '0')][one-getCnt(strs[ind], '1')];
                    dp[ind][zero][one] = max(pick, not_pick);
                }
            }
        }
        return dp[sz-1][m][n];
    }
};


// space optimized
// tc -> O(sz*n*m), sc -> O(2*n*m)
class Solution {
public:
    int getCnt(string& s, char ch){
        int cnt = 0;
        for(char c : s){
            if(c==ch)  cnt++;
        }
        return cnt;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>> prev(m+1, vector<int> (n+1,0));
        for(int zero=0; zero<=m; zero++){
            for(int one=0; one<=n; one++){
                if(zero>=getCnt(strs[0], '0') && one>=getCnt(strs[0], '1')) prev[zero][one]=1;
                else prev[zero][one]=0;
            }
        }
        for(int ind=1; ind<sz; ind++){
            vector<vector<int>> curr(m+1, vector<int> (n+1,0));
            for(int zero=0; zero<=m; zero++){
                for(int one=0; one<=n; one++){
                    int not_pick = prev[zero][one];
                    int pick = 0;
                    if(zero >= getCnt(strs[ind], '0') && one >= getCnt(strs[ind], '1'))
                        pick = 1 + prev[zero-getCnt(strs[ind], '0')][one-getCnt(strs[ind], '1')];
                    curr[zero][one] = max(pick, not_pick);
                }
            }
            prev = curr;
        }
        return prev[m][n];
    }
};
