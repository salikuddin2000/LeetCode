class Solution {
public:
    vector<int>mem;
    int solve(vector<int>&coins,int amount){
        if(amount==0){
            return 0;
        } else if(mem[amount]!=-1){
            return mem[amount];
        } else {
            int ans=1e9;
            for(int i=0;i<coins.size();i++){
                if(coins[i]<=amount){
                    ans=min(ans,1+solve(coins,amount-coins[i]));
                }
            }
            return mem[amount]=ans;
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        mem=vector<int>(amount+1,-1);
        int ans=solve(coins,amount);
        return ans>=1e9?-1:ans;
    }
};