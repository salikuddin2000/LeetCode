class Solution {
public:
    bool possible(vector<int> &bloomDay,int m, int k,int days){
        int temp=k;
        for(int x:bloomDay){
            if(x<=days){
                temp--;
            }
            else temp=k;
            if(temp==0){ 
                m--;
                temp=k;
            }
            if(m==0) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m*k>n) return-1;
        
        int end=bloomDay[0], start=bloomDay[0];
        
        for(int x:bloomDay){
            end=max(end,x);
            start=min(start,x);
        }
        
        while(start<end){
            int mid=(start+end)/2;
            if(possible(bloomDay,m,k,mid)){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
        
    }
};