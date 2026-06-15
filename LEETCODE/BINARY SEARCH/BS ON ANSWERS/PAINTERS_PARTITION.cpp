/*
link: https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&count=25&page=1&search=&sort_entity=order&sort_order=ASC

Painter's Partition
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

we check for all maxTime from max_element(arr) to sumOfAllEle(arr)
if that value satisfies the condition that k painters can complete the work, then this value is potential ans, and we need to consider the minimum of them
We can use BS for maxTime
*/


bool isPossible(int maxTime, vector<int>&nums, int k){
    int time = 0, noPainter=1;
    for(int i=0;i<nums.size();i++){
        if(time+nums[i]<=maxTime){
            time += nums[i];
        }
        else{
            noPainter++;
            time = nums[i];
        }
    }
    if(noPainter<=k)    return true;
    return false;
}
int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = 0;
    for (int i = 0; i < boards.size(); i++) high += boards[i];
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(mid, boards, k)){
            high = mid-1;
            ans = min(ans, mid);
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}