class Solution {
public:
    bool helper(vector<vector<char>>& board,string &word,int strPos,int i,int j){
        if(strPos==word.size()) return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()) return false;
        if(word[strPos]!=board[i][j]) return false;
        else{
            board[i][j]='0';
            bool ans=helper(board,word,strPos+1,i+1,j)||helper(board,word,strPos+1,i-1,j)||helper(board,word,strPos+1,i,j+1)||helper(board,word,strPos+1,i,j-1);
            board[i][j]=word[strPos];
            return ans;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]&&helper(board,word,0,i,j))return true;
            }
        }
        return false;
    }
};