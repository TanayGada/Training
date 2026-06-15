/*
link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array

K-th element of two Arrays
Given two sorted arrays arr1 and arr2 of sizes n and m respectively and an element k. The task is to find the element that would be at the kth position of the combined sorted array.

Approach remains same as Median of 2 Sorted Arrays
just replace left by k
Also if arr1 has 5 elements and arr2 has 5 elements
We want to find the 7th element
So If we take 5 elements from arr2, then too we need 2 elements from arr1
Hence low = max(0, n2-k)
high = min(n1, k)

*/

class Solution {
  public:
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2>n1)   return kthElement(nums2,nums1,k);
        int low = max(0, k-n2), high = min(k,n1);
        int n = n1 + n2;
        while(low<=high){
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            int mid1 = low+(high-low)/2;
            int mid2 = k - mid1;
            if(mid1<n1) r1 = nums1[mid1];
            if(mid1-1>=0)    l1 = nums1[mid1-1];
            if(mid2<n2) r2 = nums2[mid2];
            if(mid2-1>=0)    l2 = nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2)  high = mid1-1;
            else if(l2>r1)  low = mid1+1;
        }
        return 10;
    }
};