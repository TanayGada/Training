/*
https://leetcode.com/problems/merge-intervals/description/

Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

We sort the intervals based on their start time
We compare end of an interval and start of next intervals 
if they overlap, we merge them and add them to ans
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        sort(intervals.begin(), intervals.end());
        while(i<n){
            int j = i+1;
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(j<n && end>=intervals[j][0]){
                start = min(start, intervals[j][0]);
                end = max(end, intervals[j][1]);
                j++;
            }
            ans.push_back({start,end});
            i = j;
        }
        return ans;
    }
};