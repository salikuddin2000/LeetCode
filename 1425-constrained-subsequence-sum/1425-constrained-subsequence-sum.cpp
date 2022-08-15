class Solution {
public:

    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        int n = nums.size();
        int ans = INT_MIN;
    
        for(int i=0;i<n;i++){
        
        while(!dq.empty() && i-dq.front().second>k){
            dq.pop_front();
        }
        
        if(dq.empty()){
            dq.push_back({nums[i],i});
            ans = max(ans, nums[i]);
        }
        else{
            
            int x = dq.front().first+nums[i];
            x = max(x,nums[i]);
            ans = max(ans,x);
            while(!dq.empty() && dq.back().first<x)
                dq.pop_back();
            dq.push_back({x,i});
            }
        }
    return ans;
    }
};