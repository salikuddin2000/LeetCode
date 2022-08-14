class Solution {
    vector<int> dp=std::vector<int>(1e5,INT_MAX);
public:
    int numSquares(int n) {
        if(n==0||n==1||n==2||n==3) return n;
        if(dp[n]!=INT_MAX) return dp[n];
        int sq=sqrt(n);
        for(int i=1;i<=sq;i++){
            dp[n]=min(dp[n],numSquares(n-i*i)+1);
        }
        return dp[n];
    }
};