/*
link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

Minimum Number of Days to Make m Bouquets
You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Here the main catch is that to make a bouquet, there should be consecutive k bloomed flowers.
We check the above condition by simple Array Operations
We apply Binary Search on Answer i.e. days required
*/




class Solution {
public:
    bool isPossible(int mid, vector<int>& bloomDay, int m, int k){
        int c = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                c++;
                if(c==k){
                    m--;
                    c=0;
                }
            }
            else c=0;
        }
        if(m<=0)  return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            cout<<mid<<" ";
            if(isPossible(mid,bloomDay,m,k)){
                high = mid-1;
                ans = min(ans, mid);
            }
            else{
                low = mid+1;
            }
        }
        if(ans==INT_MAX)    return -1;
        return ans;
    }
};