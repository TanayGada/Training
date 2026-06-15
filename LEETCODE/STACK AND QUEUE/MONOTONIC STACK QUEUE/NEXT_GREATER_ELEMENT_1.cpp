/*
https://leetcode.com/problems/next-greater-element-i/description/

Next Greater Element I
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

whenever we store elements in some specific order into a stack we call the stack as monotonic stack
order can be anything, but should be something

We need to store NGE for all elements in the array, if there is none, we store -1
if we are at index i, and we need to check from i+1 to n and get the next greater element
We need to run a loop from i+1 to n for every i, so it would take O(n^2)
We can instead start from end and store the NGE for every element
i.e. we maintain a stack and store all elements in a strictly decreasing order
consider an array => 1 3 4 2
for 2
stack => [2
nge(2) = -1
for 4
stack => [4
nge(4) = -1
for 3
stack = [4 3
nge(3) = 4
for 1
stack => [4 3 1
nge(1) = 3
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size(); 
        stack<int> st;
        map<int,int> NGE;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty())  NGE[nums2[i]] = -1;
            else{
                NGE[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        int n1 = nums1.size();
        for(int i = 0; i<n1; i++){
            ans.push_back(NGE[nums1[i]]);
        }
        return ans;
    }
};