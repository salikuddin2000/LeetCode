class Solution {
public:
    void visit(vector<vector<char>>& grid,int i,int j,int& m,int& n){
        if(i==m || j==n || i<0 || j<0 || grid[i][j]=='0')
            return;
        grid[i][j]='0';
        visit(grid,i,j+1,m,n);
        visit(grid,i+1,j,m,n);
        visit(grid,i,j-1,m,n);
        visit(grid,i-1,j,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    visit(grid,i,j,m,n);
                    islands++;
                }
            }
        }
        return islands;
    }
};