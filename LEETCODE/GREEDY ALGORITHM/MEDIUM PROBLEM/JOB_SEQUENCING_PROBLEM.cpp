/*
https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

Job Sequencing Problem
Given a set of n jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.

We sort jobs based on profit in non-increasing order
We create a hashMap of size maxDeadline 
main idea here is to get the most profitable job as late as possible i.e. nearest to its deadline

*/

class Solution 
{
    public:
    bool static comp(Job a, Job b){
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        int maxDeadline = INT_MIN;
        for(int i=0;i<n;i++){
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        vector<int> deadHash(maxDeadline,-1);
        int cnt=0, profit=0;
        for(int i=0;i<n;i++){
            for(int j = arr[i].dead-1; j>=0; j--){
                if(deadHash[j]==-1) {
                    deadHash[j] = 0;
                    cnt++;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, profit};
    } 
};