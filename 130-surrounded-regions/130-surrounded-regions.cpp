class Solution {
public:
    void helper(vector<vector<char>> &board,int j,int i,vector<pair<int,int>> &dirs,int n,int m){
        if(i<0||j<0||j==n||i==m||board[j][i]=='X'||board[j][i]=='!') return;
        board[j][i]='!';
        for(auto d:dirs){
            int x=j+d.first;
            int y=i+d.second;
            helper(board,x,y,dirs,n,m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        
        vector<pair<int,int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')helper(board,0,i,dirs,n,m);
        }
        for(int j=0;j<n;j++){
            if(board[j][m-1]=='O')helper(board,j,m-1,dirs,n,m);
        }
        for(int i=m-1;i>=0;i--){
            if(board[n-1][i]=='O')helper(board,n-1,i,dirs,n,m);
        }
        for(int j=n-1;j>=0;j--){
            if(board[j][0]=='O')helper(board,j,0,dirs,n,m);
        }
        
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(board[j][i]=='O') board[j][i]='X';
                if(board[j][i]=='!') board[j][i]='O';
            }
        }
    }
};