class Solution {
    int m;
public:
    int helper(vector<vector<int>>& matrix,int row,int col,vector<vector<int>> &dp){
        if(col<=-1||col>=m) return INT_MAX;
        if(row==0) return matrix[0][col];
        if(dp[row][col]!=-1) return dp[row][col];
        
        int up=helper(matrix,row-1,col,dp);
        int rightUp=helper(matrix,row-1,col+1,dp);
        int leftUp=helper(matrix,row-1,col-1,dp);
        
        return dp[row][col]=matrix[row][col]+min(min(rightUp,leftUp),up);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int res=INT_MAX;
        for(int i=0;i<m;i++){
            res=min(res,helper(matrix,n-1,i,dp));
        }
        return res;
    }
};