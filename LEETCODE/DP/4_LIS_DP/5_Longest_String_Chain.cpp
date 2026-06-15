// link: https://leetcode.com/problems/longest-string-chain/
// isChain condition instead of standard LIS condition

//tc -> O(n*n), sc -> O(n)
class Solution {
public:
    static bool comp(string& s1, string& s2){
        return s1.size()<s2.size();
    }

    bool isChain(string& s1, string& s2){
        if(s1.size()+1!=s2.size())  return false;
        int first = 0;
        int second = 0;
        while(second<s2.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                second++;
            }
        }
        return (s1.size()==first && s2.size()==second);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n+1, 1);
        sort(words.begin(), words.end(), comp);
        int maxi = 0;
        for(string s : words)   cout<<s<<endl;
        for(int curr = 0; curr<n; curr++){
            for(int prev=0; prev<curr; prev++){
                if(isChain(words[prev], words[curr])) dp[curr] = max(dp[curr], dp[prev]+1);
            }
            maxi = max(maxi, dp[curr]);
        }
        return maxi;
    }
};