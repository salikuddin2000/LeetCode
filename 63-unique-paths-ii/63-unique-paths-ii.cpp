class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid,int i,int j,int n,int m,vector<vector<int>> &dp){
        if(i==m||j==n||obstacleGrid[i][j]==1) return 0;
        if(i==m-1&&j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]= helper(obstacleGrid,i+1,j,n,m,dp)+helper(obstacleGrid,i,j+1,n,m,dp);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(obstacleGrid,0,0,n,m,dp);
    }
};