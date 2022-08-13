class Solution {

public:
    int sell(vector<int>& prices,int pos,int n,vector<int> &minPrice){
        if(pos==n-1) return prices[n-1];
        if(minPrice[pos]!=-1) return minPrice[pos];
        else minPrice[pos]= max(prices[pos],sell(prices,pos+1,n,minPrice));
        return minPrice[pos];
    }
    int buy(vector<int>& prices,int pos,int n,vector<int> &minPrice){
        if(pos==n-1) return 0;
        return max((sell(prices,pos+1,n,minPrice)-prices[pos]),buy(prices,pos+1,n,minPrice));
    }
    int maxProfit(vector<int>& prices) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=prices.size();  
        vector<int>minPrice=std:: vector<int>(n+1,-1);
        return buy(prices,0,n,minPrice);
    }
};