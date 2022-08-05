class Solution {
public:
int m, n;

 int dfs(vector<vector<int>>& memo, int i, int j, vector<vector<int>>& matrix) {
    
    // if(i < 0 || j < 0) return 0;
    // if(i >= m || j >= n) return 0;
    
    if(memo[i][j] > 0) return memo[i][j];
    
    int path = 1;
    
    // downward
    if(i + 1 < m && matrix[i+1][j] > matrix[i][j])
        path = max(path, 1 + dfs(memo, i+1, j, matrix));
    
    // upward
    if(i - 1 >= 0 && matrix[i-1][j] > matrix[i][j])
        path = max(path, 1 + dfs(memo, i-1, j, matrix));
    
    // left
    if(j - 1 >= 0 && matrix[i][j-1] > matrix[i][j])
        path = max(path, 1 + dfs(memo, i, j-1, matrix));
    
    // right
    if(j + 1 < n && matrix[i][j+1] > matrix[i][j])
        path = max(path, 1 + dfs(memo, i, j+1, matrix));
    
    memo[i][j] = path;
    
    return path;        
    
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();
    
    int res = 0;
    
    if(m<1)
        return res;
    
    vector<vector<int>> memo(m, vector<int>(n, 0));
    
    for(int i = 0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            res = max(res, dfs(memo, i, j, matrix));
        }
    }
    return res;        
}
};