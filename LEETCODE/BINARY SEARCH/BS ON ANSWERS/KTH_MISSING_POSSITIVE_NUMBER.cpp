/*
link: https://leetcode.com/problems/kth-missing-positive-number/description/

Kth Missing Positive Number
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

arr   =>   2 3 4 7 11
ind+1 =>   1 2 3 4 5
miss[i] = arr[i] - (ind+1)
miss  =>   1 1 1 3 6
if k = 5 => ans=9
we find the range between which k is present i.e. miss-> 3 and 6
miss  =>    1   1   1   3   6
                      high low
ans = arr[high] + extra
extra = k - miss[high]
extra = k - (arr[high] - (high+1))
ans = arr[high] + k - (arr[high] - (high+1))
ans = arr[high] + k - arr[high] + (high+1)
ans = k + high + 1;
also we know => low = high+1
ans = k + low
*/



class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int miss = arr[mid] - mid -1;
            if(k>miss){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return k+high+1;
    }
};
