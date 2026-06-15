/*
https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

Minimum Platforms
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
*/

/*
we need to calculate the maximum intersection between trains in a particular time
but this would take a O(n^2) time
We can try to optimize it
We can sort both arr and dep by time
We can maintain a counter 
which increases if a train arrives and decreases if a train departs
We traverse through both arrays simultaneously based on time
*/

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int arrInd = 0, depInd = 0;
    	int ans = 0, cnt=0;
    	while(arrInd<n && depInd<n){
    	    if(arr[arrInd]<=dep[depInd]){
    	          cnt++;
    	          arrInd++;
    	    }
    	    else{
    	         cnt--;
    	         depInd++;
    	    }
    	    ans = max(cnt, ans);
    	}
    	return ans;
    }
};