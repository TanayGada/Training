/*
link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

1. Calculate the totalNumber of elements in both arrays
2. If totalNumber is odd
    (totalNumber/2 + 1)th element is the median element
   If totalNumber is even
    (totalNumber/2)th element is the median element
3. So using binary search we try to get smallest (totalNumber/2) elements from both array and eventually get the median element.
4. We want l1,l2,r1,r1
5. l1 & l2 are last elements from arr1 & arr2 respec. which will be on the LHS
6. r1 & r2 are first elements from arr1 & arr2 respec. which will be on the RHS
7. We get l1,l2,r1,r1 values by using binary search 
8. l1<=r2 and l2<=r1 is the necessary condition
9. We apply binary search on arr1 (arr1 is always bigger ) and get the mid1
10. we get mid2 = ((totalNumber/2)-mid1)
11. l1 = arr1[mid1-1], l2 = arr2[mid2-1], r1 = arr1[mid1], r2 = arr2[mid]
12. If totalNumber is odd, median is (max(l1,l2))
    Otherwise, medain is (max(l1,l2)+min(r1,r2))/2
We know that (l1+l2) is always equal to (totalNumber/2)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2)   return findMedianSortedArrays(nums2,nums1);
        int low = 0, high = n1;
        int left = (n1 + n2 +1)/2;
        int n = n1 + n2;
        
        while(low<=high){
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            int mid1 = (low+high)/2;
            int mid2 = left - mid1;
            if(mid1<n1) r1 = nums1[mid1];
            if(mid1-1>=0)    l1 = nums1[mid1-1];
            if(mid2<n2) r2 = nums2[mid2];
            if(mid2-1>=0)    l2 = nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if((n%2)!=0) return max(l1,l2);
                return ((double)((max(l1,l2)+min(r1,r2))/2.0));
                
            }
            else if(l1>r2)  high = mid1-1;
            else if(l2>r1)  low = mid1+1;
        }
        return 10;
    }
};