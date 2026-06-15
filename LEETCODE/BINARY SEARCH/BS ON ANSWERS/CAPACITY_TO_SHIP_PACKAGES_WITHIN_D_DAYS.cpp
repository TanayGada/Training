/*
link: 

Capacity To Ship Packages Within D Days
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

for values of weight (which we get through binary search)
we check if we can fit all items in "days" day and within a bag of "weight" weight
*/


class Solution {

private:
    bool isPossible(int weight, vector<int>& weights, int days){
        int sum =0;
        int c=1;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>weight)   return false;
            if((sum+weights[i])<=weight){
                sum += weights[i];
            }
            else{
                c++;
                sum=0;
                i = i-1;
            }
        }
        if(c<=days) return true;
        return false;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1, high = 0;
        for(int i=0;i<weights.size();i++)   high +=weights[i];
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(mid, weights, days)){
                high = mid-1;
                ans = min(ans, mid);
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};