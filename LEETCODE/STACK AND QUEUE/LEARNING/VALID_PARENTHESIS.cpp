/*
Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

tc=>O(n), sc=>O(n)
cases to be handled => '(', ')', '()'
*/

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else{
                char stackChar = '0';
                if(!st.empty()) stackChar = st.top();
                st.pop();
                if((s[i]==')' && stackChar=='(') || (s[i]==']' && stackChar=='[') || (s[i]=='}' && stackChar=='{')){
                    continue;
                }
                else return false;
            }
        }
        if(st.empty())  return true;
        return false;
    }
};