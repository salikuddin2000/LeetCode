class Solution {
public:
    bool possible(vector<int>& nums,int t,int div){
        int sum=0;
        for(int x:nums){
            sum+=ceil((float)x/(float)div);
        }
        if(sum>t) return false;
        else return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n=nums.size();
        int start=1;
        int end=nums[0];
        for(int x:nums) end=max(end,x);
        
        while(start<end){
            int mid=(start+end)/2;
            if(possible(nums,threshold,mid)){
                end=mid;
            }
            else{
            cout<<mid<<" ";
                start=mid+1;
            }
        }
        return start;
    }
};