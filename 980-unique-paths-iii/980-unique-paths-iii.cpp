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
    int helper(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i==-1||j==-1||i==m||j==n||grid[i][j]==-1||grid[i][j]==1) return 0;
        if(grid[i][j]==2&&isVisited(grid)) return 1;
        if(grid[i][j]==2) return 0;
        grid[i][j]=1;
        int ans=helper(grid,i-1,j,m,n)+helper(grid,i+1,j,m,n)+helper(grid,i,j-1,m,n)+helper(grid,i,j+1,m,n);
        grid[i][j]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
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
        return helper(grid,s,e,m,n);
    }
};