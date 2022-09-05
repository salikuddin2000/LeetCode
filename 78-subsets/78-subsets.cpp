class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<(1<<n); i++){
            vector<int> v;
            int j=0, mask=i;
            while(mask){
                if(mask&1)
                    v.push_back(nums[j]);
                mask>>=1, j++;
            }
            ans.push_back(v);
        }
        return ans;
    }
};