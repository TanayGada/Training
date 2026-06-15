/*
https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-postfix-conversion

Prefix to Postfix Conversion
1. we traverse from the end
2. When we get a operand, we push operand onto the stack
3. When we get a operator, we push op1 + op2 + operator onto the stack

tc -> O(n) + O(n),  extra O(n) is due to string concatenation
sc => O(n)
*/

class Solution {
  public:
    string preToPost(string pre_exp){
        // Write your code here
        stack<string> st;
        int n = pre_exp.size();
        for(int i=n-1;i>=0;i--){
            if(('0'<=pre_exp[i] && pre_exp[i]<='9') || ('a'<=pre_exp[i] && pre_exp[i]<='z') || ('A'<=pre_exp[i] && pre_exp[i]<='Z')){
                st.push(string(1,pre_exp[i]));
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push(op1 + op2 +pre_exp[i]);
            }
        }
        string ans = st.top();
        
        return ans;
    }
};