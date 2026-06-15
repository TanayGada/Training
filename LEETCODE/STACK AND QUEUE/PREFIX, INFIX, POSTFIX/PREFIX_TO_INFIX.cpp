/*
https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-infix-conversion

Prefix to Infix Conversion
We iterate from the back
1. we push operand onto the stack
2. when we get the operator, we pop top 2 ele from stack and push onto stack having (op1 + s[i] + op2)
3. at the end the top of the stack is the required infix expression

tc -> O(n) + O(n),  extra O(n) is due to string concatenation
sc => O(n)
*/

class Solution {
  public:
    string preToInfix(string pre_exp) {
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
                st.push('(' + op1 + pre_exp[i] + op2 + ')');
            }
        }
        return st.top();
    }
};