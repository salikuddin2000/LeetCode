int buy(vector<int> &prices,int pos,int n,vector<int> &maxPrice){
if(pos==n) return 0;
if(maxPrice[pos]!=-1) return maxPrice[pos];
// int profit=0;
for(int i=pos+1;i<n;i++){
maxPrice[pos]=max(maxPrice[pos],(prices[i]-prices[pos]+buy(prices,i+1,n,maxPrice)));
}
maxPrice[pos]=max(maxPrice[pos],buy(prices,pos+1,n,maxPrice));
return maxPrice[pos];
}
int maxProfit(vector<int>& prices) {
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int n=prices.size();
vector<int>maxPrice(n+1,-1);
return buy(prices,0,n,maxPrice);
}