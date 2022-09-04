class Solution {
public:
    bool possible(vector<int> &weights,int days,int limit){
        int temp=0;
        for(int x:weights){
            // if(limit==12) cout<<x<<":"<<days<<" ";
            if(temp+x<=limit) temp+=x;
            else{
                temp=x;
                days--;
            }
            if(days==0) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=weights[0],end=0;
        for(int x:weights){
            start=max(start,x);
            end+=x;
        }
        while(start<end){
            int mid=(start+end)/2;
            if(possible(weights,days,mid)){cout<<mid<<" "; end=mid;}
            else start=mid+1;
        }
        return start;
    }
};