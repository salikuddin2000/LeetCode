class Solution {
public:
    void helper(vector<int>& candidates,int target, int pos,int n,vector<vector<int>> &ans, vector<int> sumarr){
        if(target==0){ 
            ans.push_back(sumarr);
            return;
        }
        if(pos==-1) return;
        helper(candidates,target,pos-1,n,ans,sumarr);
        for(int i=candidates[pos];target>=0;){
            target-=i;
            sumarr.push_back(candidates[pos]);
            helper(candidates,target,pos-1,n,ans,sumarr);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        helper(candidates,target,n-1,n,ans,{});
        return ans;
    }
};