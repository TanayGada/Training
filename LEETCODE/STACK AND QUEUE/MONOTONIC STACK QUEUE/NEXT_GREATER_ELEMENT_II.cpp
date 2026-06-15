/*
https://leetcode.com/problems/next-greater-element-ii/description/

Next Greater Element II
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Additional thing here is that we used to look to the right of index i for NGE
but here if we dont find the NGE in the right direction, we search for it from start i.e. circular order

*/