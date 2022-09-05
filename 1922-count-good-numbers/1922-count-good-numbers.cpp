class Solution {
    #define ll long long
public:
    
    ll M=1e9+7;
    ll BinaryExp(ll a,ll b){
        ll ans=1;
        while(b){
            if(b&1) ans=(ans*a)%M;
            a=(a*a)%M;
            b>>=1;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        ll even=(n+1LL)/2;
        ll odd=n-even;
        
        return (BinaryExp(5LL,even)%M * BinaryExp(4LL,odd)%M)%M;
    }
};