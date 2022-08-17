class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,int n,int m, vector<vector<int>> &dp){
        if(i==n||j==m) return INT_MAX-10000;
        if(i==n-1&&j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i+1][j]=helper(grid,i+1,j,n,m,dp);
        dp[i][j+1]=helper(grid,i,j+1,n,m,dp);
        dp[i][j] =grid[i][j]+min(dp[i+1][j] ,dp[i][j+1] );
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(grid,0,0,n,m,dp);
    }
};