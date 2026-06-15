// link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// max_length = n
// segment with size sz have value price[sz]
// maximise value

// memoized
// tc -> O(sz*sz), sc -> O(sz*sz) + O(sz)
class Solution {
  public:
    int func(int sz, int length, vector<int>& price, vector<vector<int>>& dp){
        if(sz==0){
            return (length)*price[0];
        }
        if(dp[sz][length]!=-1)  return dp[sz][length];
        int pick_curr = 0;
        if(length>=(sz+1))  pick_curr = price[sz] + func(sz, length-sz-1, price, dp);
        int pick_nxt = func(sz-1, length, price, dp);
        return dp[sz][length] = max(pick_curr, pick_nxt);
    }
    int cutRod(vector<int> &price) {
        // code here
        int maxLength = price.size();
        vector<vector<int>> dp(maxLength, vector<int> (maxLength+1, -1));
        return func(maxLength-1, maxLength, price, dp);
    }
};

// tabulation
// tc -> O(sz*sz), sc -> O(sz*sz)
class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int maxLength = price.size();
        vector<vector<int>> dp(maxLength, vector<int> (maxLength+1, 0));
        for(int length=0; length<=maxLength; length++){
            dp[0][length] = (length)*price[0];
        }
        for(int sz=1; sz<maxLength; sz++){
            for(int length=0; length<=maxLength; length++){
                int pick_curr = 0;
                if(length>=(sz+1))  pick_curr = price[sz] + dp[sz][length-sz-1];
                int pick_nxt = dp[sz-1][length];
                dp[sz][length] = max(pick_curr, pick_nxt);
            }
        }
        return dp[maxLength-1][maxLength];
    }
};

// space optimized
// tc -> O(sz*sz), sc -> O(2*sz)
class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int maxLength = price.size();
        vector<int> prev(maxLength+1, 0);
        for(int length=0; length<=maxLength; length++){
            prev[length] = (length)*price[0];
        }
        for(int sz=1; sz<maxLength; sz++){
            vector<int> curr = prev;
            for(int length=0; length<=maxLength; length++){
                int pick_curr = 0;
                if(length>=(sz+1))  pick_curr = price[sz] + curr[length-sz-1];
                int pick_nxt = prev[length];
                curr[length] = max(pick_curr, pick_nxt);
            }
            prev = curr;
        }
        return prev[maxLength];
    }
};