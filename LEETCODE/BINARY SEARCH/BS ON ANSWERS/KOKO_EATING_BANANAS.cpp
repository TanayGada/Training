/*
link: https://leetcode.com/problems/koko-eating-bananas/description/

Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

We can check for a value of k whether it is possible or not in O(n)
We need to check for all k => so total tc is O(n^2)
We can see it is like a step function i.e. for some consecutive k, ans would be false and then true => so we can apply a binary search on k
So tc => (nlogn)

*/


class Solution {
public:

    bool isPossible(int k, vector<int>&piles, int h){
        long long reqHours = 0;
        for(int i=0;i<piles.size();i++){
            reqHours += (piles[i]+k-1)/k;
        }
        if(reqHours<=h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        long long high = *max_element(piles.begin(),piles.end()) ;
        long long ans = INT_MAX;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(isPossible(mid, piles, h)){
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