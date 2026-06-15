/*
LINK: https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root

Square root of a number
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

assume mid as sqrt and compare mid*mid to number x
*/


class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int low = 1;
        long long int high = x;
        while(low<=high){
            long long int mid = (low+high)/2;
            long long int sq = mid*mid;
            if(sq >x)   high = mid-1;
            else   low = mid+1;
        }
        return high;
    }
};