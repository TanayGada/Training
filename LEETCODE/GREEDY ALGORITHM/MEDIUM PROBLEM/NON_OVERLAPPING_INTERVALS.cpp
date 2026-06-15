/*
https://leetcode.com/problems/non-overlapping-intervals/description/

Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

This is similar to N meetings in one room problem
We sort array according to end time and try to take maximum number of intervals so that they donot overlap 
Hence we get the number of intervals which are causing overlapping by subtracting non-overlapping from size 

tc => O(nlogn), sc => O(1)
*/

class Solution {
public:
    bool static comp(vector<int> &a,vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int prevEnd = INT_MIN, cnt=0;
        for(int i=0;i<n;i++){
            if(prevEnd <= intervals[i][0]){
                prevEnd = intervals[i][1];
            }
            else cnt++;
        }
        return cnt;
    }
};