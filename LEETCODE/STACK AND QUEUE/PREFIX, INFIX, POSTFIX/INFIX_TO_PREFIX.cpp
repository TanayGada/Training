/*

Convert an infix to prefix 
1. Reverse the Infix
2. Infix to Postfix (under one additional condition)
3. Reverse the PostfixExpression

while reversing, need to take care of brackets, they needs to be reverse, so we just reverses the conditions for brackets

Additional Condition
during infixToPostfix, we add operator to stack if(priority(top)<priority(operator))
but here, we add operator to stack if(priority(top)<=priority(operator))

for equal and greater priority of operator than top, we push
*/


class Solution {
  public:
    int priority(char op){
        if(op=='^') return 3;
        if(op=='*' || op=='/')  return 2;
        if(op=='+' || op=='-')  return 1;
        return 0;
    }
    
    string infixToPrefix(string s) {
        // Your code here
        int n = s.size();
        reverse(s.begin(),s.end());
        string ans = "";
        stack<char> st;
        for(int i=0;i<n; i++){
            if(('0' <= s[i] && s[i]<='9') || ('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z'))    ans+=s[i];
            else if(s[i]==')'){
                st.push(s[i]);
            }
            else if(s[i]=='('){
                while(!st.empty() && st.top()!=')'){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                if(st.size()==0){
                    st.push(s[i]);
                    continue;
                }
                if(priority(st.top())<=priority(s[i])){
                    st.push(s[i]);
                }
                else{
                    while(!st.empty() && priority(st.top())>priority(s[i])){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};