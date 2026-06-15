/*
link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

Fractional Knapsack
Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack. Return a double value representing the maximum value in knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. The details of structure/class is defined in the comments above the given function.

We check value/weight for each Item
Implementation of comp() is important => use of static keyword
*/

/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {

  public:  
    bool static comp(Item a, Item b){
        double v1 = a.value/(double(a.weight));
        double v2 = b.value/(double(b.weight));
        return v1>v2;
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr, arr+n, comp);
        double value = 0;
        for(int i=0;i<n;i++){
            if(w<0) break;
            else{
                if(arr[i].weight<=w){
                    w-=arr[i].weight;
                    value +=arr[i].value;
                }
                else{
                    value+=(w*(arr[i].value/double(arr[i].weight)));
                    w=0;
                }
            }
        }
        return value;
        
    }
};
