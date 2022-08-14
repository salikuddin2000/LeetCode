static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();
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