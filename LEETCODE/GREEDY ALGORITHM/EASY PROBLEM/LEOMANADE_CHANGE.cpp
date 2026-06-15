/*
link: https://leetcode.com/problems/lemonade-change/description/

Lemonade Change
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

we maintain a map for keeping the count of presence of 5 unit, 10 unit, 20 unit denominations

if, we get a 10 unit note
we check if we have a 5 unit note or not, if we have we decrement the cntOf5 by 1 and cntOf10 by 1 and continue, else return false

if we get a 20 unit note
We check if we have a 10 unit Note and a 5 unit Note or not, if we dont have, we check for three 5 unit Note
and decrement cntOf5 or cntOf10 accordingly and increase cntOf20
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>mp;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5) mp[5]++;
            else if(bills[i]==10)
            {
                if(mp[5]<1)    return false;
                mp[5]--;
                mp[10]++;
            }
            else if(bills[i]==20){
                if(mp[10]>=1 && mp[5]>=1){
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>=3){
                    mp[5]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};