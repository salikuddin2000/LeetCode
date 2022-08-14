class Solution {
public:
    int helper(vector<int> &nums,int target,int pos,int n,vector<vector<int>> &dp){
        if(pos==n&&target==0) return 1;
        if(pos==n&&target!=0) return 0;
        if(dp[pos][target+1000]!=-1) return dp[pos][target+1000];
        dp[pos][target+1000]= helper(nums,target+nums[pos],pos+1,n,dp)+helper(nums,target-nums[pos],pos+1,n,dp);
        return dp[pos][target+1000];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(100000,-1));
        return helper(nums,target,0,n,dp);
    }
};