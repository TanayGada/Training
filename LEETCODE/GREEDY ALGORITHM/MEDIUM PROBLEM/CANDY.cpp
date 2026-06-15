/*
https://leetcode.com/problems/candy/

Candy
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

We can greedily allocate candies to children by giving just 1 more than their neighbors if the child has more ratings than its neighbors
We can do this in 2 pass
first we start from start and allocate candies by only considering the left neighbors and allocate the candies
then we start from end and allocate candies by only considering the right neighbors and allocate the candies
we then take the maximum at each index as the finalCandy to be allocated
time => O(2*n), space => O(2*n)
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = 1;
        //checking with left element in array
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
            else left[i] = 1;
        }
        //checking with right element in array
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i] = right[i+1]+1;
            }
            else right[i] = 1;
        }
        int sum=0;
        for(int i=0;i<n;i++)    sum += max(right[i], left[i]);
        return sum;
    }
};

/*
lets optimize space complexity to O(n)
We can avoid taking right array and try to do all the calculation in the left array itself
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,0);
        left[0] = 1;
        //checking with left element in array
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
            else left[i] = 1;
        }
        //checking with right element in array
        
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] ){
                if(left[i]<=left[i+1]){
                    left[i] = left[i+1]+1;
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)    sum += left[i];
        return sum;
    }
};


/*
lets reduce the space complexity of O(n) to O(1)

we convert the arrayElements into slopes
slopes can be on 3 types => 1.increasing 2.decreasing 3.plateau
for increasing slope, we increment the counter and add that into sum
for decreasing too, we increment the counter and add that into sum
in case of plateau, counter remains 1 and we add that into sum
in case of increasing and decreasing, we need to adjust the peak element as increasing curve may be shorter than decreasing curve
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int down = 0;
        int sum = 1;
        int i = 1;
        int n = ratings.size();
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                sum += 1;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peak)   sum += (down-peak);
        }
        return sum;
    }
};