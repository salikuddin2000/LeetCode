class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0;
        int maxSum=nums[0];
        for(auto x:nums){
            currSum+=x;
            if(currSum<=x)currSum=x;
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};