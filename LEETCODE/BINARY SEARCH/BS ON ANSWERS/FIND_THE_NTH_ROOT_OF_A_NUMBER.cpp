/*
link: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m

Find Nth root of M
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).

we assume mid to be nth root and check mid^n with x
*/


class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int low = 1;
	    int high = m;
	    while(low<=high){
	        long long int mid = (low+high)/2;
	        long long int val = 1;
	        for(int i=0;i<n;i++)    val = val*mid;
	        if(val==m)  return mid;
	        if(val<m)  low=mid+1;
	        else    high = mid-1;
	    }
	return -1;
	}  
};