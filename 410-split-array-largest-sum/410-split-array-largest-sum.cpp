class Solution {
public:
    bool isPossible(vector<int> &nums,int m,int maxSum){
        int sum=0;
        for(int x:nums){
            if(sum+x<=maxSum) sum+=x;
            else{
                sum=x;
                m--;
            }
            if(m==0) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int left=nums[0],right=0;
        for(int x:nums){
            left=max(left,x);
            right+=x;
        }
        int mid;
        while(left<right){
            mid=(left+right)/2;
            if(isPossible(nums,m,mid)) right=mid;
            else left=mid+1;
        }
        return left;
    }
};