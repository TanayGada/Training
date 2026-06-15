/*
For converting an infix expression into a postfix expression
1. Whenever we see a operand, we put it into ans
2. whenever we see a operator,
    if( priority(operator) > priority(topOfStack) || stack is empty )
        push operator onto stack
    if( st.empty() && priority(operator) <= priority(topOfStack) )
        we pop operators from stack until topOfStack has less priority Operator and then push our operator
3. Whenever we get a opening bracket '(', we push it onto the stack
4. Whenever we get a closing bracket ')', we pop operators from the stack until we get the opening bracket '('
5. if string is traversed and stack is not empty, pop all elements from stack and append to ans

sc => O(n), tc=> O(n) + O(n)

We push operator to stack if priority(operator) is strictly greater than priority(topElementOfStack)
We used to pop the operator until the priority(top) was less than or equal to priority(operator)
*/

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char op){
        if(op=='^') return 3;
        if(op=='*' || op=='/')  return 2;
        if(op=='+' || op=='-')  return 1;
        if(op=='(' || op=='[' || op=='{')   return 0;
        return -1;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        int n = s.size();
        string ans = "";
        stack<char> st;
        for(int i=0;i<n; i++){
            if(('0' <= s[i] && s[i]<='9') || ('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z'))    ans+=s[i];
            else if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
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
                
                if(priority(st.top())<priority(s[i])){
                    st.push(s[i]);
                }
                else{
                    while(!st.empty() && priority(st.top())>=priority(s[i])){
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
        return ans;
    }
};