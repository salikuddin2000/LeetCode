class Solution {
public:
int solve(vector<vector<int>>&dp,int i,bool hold,vector<int>&prices)
{
    if(i>=prices.size()) 
        return 0;
    
    if(dp[i][hold]!=-1) 
        return dp[i][hold];
    
    //if we are holding it then either sell it or dont sell it 
    if(hold)
    {
        //+(prices[i]), because when we sell we get that price
        return dp[i][hold] = max(prices[i]+solve(dp,i+1,0,prices),solve(dp,i+1,1,prices));
    }
    else
    {
        //-prices[i],because when we buy we spend our money
         return dp[i][hold] = max(-prices[i] + solve(dp,i+1,1,prices),solve(dp,i+1,0,prices));       
    }
    
}

int maxProfit(vector<int>& prices) {
    
   vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
    
    //index,bool(0,0) holding nothing in the starting
    return solve(dp,0,0,prices);
}
};