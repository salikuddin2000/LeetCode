class Solution {
public:
    int helper(vector<int> &nums,int target,int pos,int n){
        if(pos==n&&target==0) return 1;
        if(pos==n&&target!=0) return 0;
        return helper(nums,target+nums[pos],pos+1,n)+helper(nums,target-nums[pos],pos+1,n);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return helper(nums,target,0,n);
    }
};