// we have 2 options
// curr character or current char + next char, such that range is from "1" to "26"
// memoized
class Solution {
public:
    vector<int> dp;
    int func(int ind, string s){
        if(ind == s.size()) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int ans = 0;
        if(s[ind]!='0')   ans+=func(ind+1, s);
        if(ind+1<s.size() && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6')))  ans+= func(ind+2, s);
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n, -1);
        return func(0, s);
    }
};

// tabulated
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i]!='0')   dp[i] += dp[i+1];
            if(i+1<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) dp[i] += dp[i+2];
        }
        return dp[0];
    }
};


// space optimized
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int first = 1, second = 0;
        int curr = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i]!='0')   curr += first;
            if(i+1<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) curr += second;
            second = first;
            first = curr;
            curr = 0;
        }
        return first;
    }
};