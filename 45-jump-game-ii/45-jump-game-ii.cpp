class Solution {
public:
    int helper(vector<int> &nums,int n,int pos,vector<int> &dp){
        if(pos>=n-1) return 0;
        if(dp[pos]!=INT_MAX-n) return dp[pos];
        int mx=nums[pos];
        // dp[pos]=INT_MAX-n;
        for(int i=1;i<=mx;i++){
            dp[pos]=min(dp[pos],helper(nums,n,pos+i,dp)+1);
        }
        return dp[pos];
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX-n);
        return helper(nums,n,0,dp);
    }
};