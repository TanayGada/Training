// ans is not storing the LIS
// we can only get size of LIS using BS approach
// we update temp to add curr element from nums, such that LIS is maintained

// tc -> O(n*logn), sc -> O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i]>temp.back())  temp.push_back(nums[i]);
            else{
                int lb = lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
                temp[lb] = nums[i];
            }
        }
        return temp.size();
    }
};

