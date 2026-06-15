/*
link: https://leetcode.com/problems/valid-parenthesis-string/

Valid Parenthesis String 
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

When we encounter '(', we increment the counter
When we encounter ')', we decrement the counter
When we encounter '*', we can increment, decrement or do nothing to counter
If at the end, the counter is 0, we say that string is balanced.
But for '*', we need to take recursive approach of trying out all 3 possibilities and even if one gives counter==0, we say it is valid
tc => O(n^3)
memoized solution
*/
class Solution {
public:
    bool isValid(int ind, string s, int cnt, vector<vector<int>>& dp){
        if(cnt<0 || cnt>=dp[0].size())   return false;  

        if(dp[ind][cnt]!=-1)    return dp[ind][cnt];
        if(ind==s.size()){
            return (cnt==0);
        }
        bool result;
        if(s[ind]=='(') result = isValid(ind+1, s, cnt+1, dp);
        else if(s[ind]==')') result = isValid(ind+1, s, cnt-1, dp);
        else{
            result = (isValid(ind+1, s, cnt, dp) || isValid(ind+1, s, cnt+1, dp) || isValid(ind+1, s, cnt-1, dp));
        }
        return dp[ind][cnt] = result;
    }

    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(2*s.size()+1,-1));
        return isValid(0,s,0, dp);
    }
};

/*
We can maintain the min and max range of counter and not the counter itself
When we encounter '(', we increment the min and max
When we encounter ')', we decrement the min and max
When we encounter '*', we increment max and decrement min
min cannot be negative, so if it becomes negative, we make it 0
If max becomes negative, we say it cannot be balanced => ')(())' max becomes -ve at start
tc => O(n)
*/

class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min<0)   min=0;
            if(max<0)   return false;
        }
        if(min==0)    return true;
        return false;
    }
};