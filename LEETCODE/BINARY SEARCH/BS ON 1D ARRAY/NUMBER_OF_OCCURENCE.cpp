/*
https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

Number of occurrence
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

upperBound - lowerBound
*/


class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int target) {
	    // code here
	    vector<int> nums;
	    for(int i=0;i<n;i++)    nums.push_back(arr[i]);
	    auto ub = upper_bound(nums.begin(), nums.end(), target);
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        int l = lb - nums.begin();
        int u = ub - nums.begin();
        
        if (lb == nums.end() || nums[l] != target) return 0;
        
        return u-l;
	}
};