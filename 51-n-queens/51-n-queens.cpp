class Solution {
public:
    void helper(int col,int n,vector<bool> &lowerDiag,vector<bool> &upperDiag,vector<bool> &leftRow,vector<string> &board, vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(!leftRow[row]&&!lowerDiag[col+row]&&!upperDiag[n-1+col-row]){
                board[row][col]='Q';
                leftRow[row]=true;
                lowerDiag[row+col]=true;
                upperDiag[n-1+col-row]=true;
                helper(col+1,n,lowerDiag,upperDiag,leftRow,board,ans);
                board[row][col]='.';
                leftRow[row]=false;
                lowerDiag[row+col]=false;
                upperDiag[n-1+col-row]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string (n,'.'));
        vector<bool> leftRow(n),lowerDiag(2*n-1),upperDiag(2*n-1);
        helper(0,n,lowerDiag,upperDiag,leftRow,board,ans);
        return ans;
        
    }
};