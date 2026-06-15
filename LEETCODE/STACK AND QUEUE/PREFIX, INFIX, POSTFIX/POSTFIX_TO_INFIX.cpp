/*
https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postfix-to-prefix-conversion

Postfix to Infix Conversion
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.

We maintain a stack and push operands into it
whenever we get a operator, we pop top 2 elements of the stack and store the 2 operands and operator as single expression back into the stack with parenthesis

tc -> O(n) + O(n),  extra O(n) is due to string concatenation
sc => O(n)
*/

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        int n = exp.size();
        for(int i=0;i<n;i++){
            if(('0'<=exp[i] && exp[i]<='9') || ('a'<=exp[i] && exp[i]<='z') || ('A'<=exp[i] && exp[i]<='Z')){
                st.push(string(1, exp[i]));
            }
            else{
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                st.push('(' + op1+exp[i]+op2 + ')');
            }
        }
        string ans = st.top();
        return ans;
    }
};