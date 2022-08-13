class Solution {
public:
    bool isVisited(vector<vector<int>> dp){
        for(auto x:dp){
            for(auto y:x){
                if(y==0) return false;
            }
        }
        return true;
    }
    int helper(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==-1||j==-1||i==m||j==n||grid[i][j]==-1||grid[i][j]==1) return 0;
        if(grid[i][j]==2&&isVisited(grid)) {cout<<"reached ";return 1;}
        if(grid[i][j]==2) return 0;
        cout<<i<<":"<<j<<" ";
        // if(dp[i][j]!=-1) return dp[i][j];
        grid[i][j]=1;
        dp[i][j]=helper(grid,i-1,j,m,n,dp)+helper(grid,i+1,j,m,n,dp)+helper(grid,i,j-1,m,n,dp)+helper(grid,i,j+1,m,n,dp);
        grid[i][j]=0;
        return dp[i][j];
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int s=-1;
        int e=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    s=i;
                    e=j;
                    break;
                }
            }
            if(s!=-1) break;
        }
        grid[s][e]=0;
        return helper(grid,s,e,m,n,dp);
    }
};