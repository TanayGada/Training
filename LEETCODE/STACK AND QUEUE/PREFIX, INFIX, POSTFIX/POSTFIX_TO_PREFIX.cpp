/*
https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postfix-to-prefix-conversion

Postfix to Prefix Conversion
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

1. When we get a operand, we push operand onto the stack
2. When we get a operator, we push operator + op2 + op1 onto the stack

tc -> O(n) + O(n),  extra O(n) is due to string concatenation
sc => O(n)
*/

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> st;
        int n = post_exp.size();
        for(int i=0;i<n;i++){
            if(('0'<=post_exp[i] && post_exp[i]<='9') || ('a'<=post_exp[i] && post_exp[i]<='z') || ('A'<=post_exp[i] && post_exp[i]<='Z')){
                st.push(string(1,post_exp[i]));
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push(post_exp[i] + op2 + op1);
            }
        }
        return st.top();
    }
};