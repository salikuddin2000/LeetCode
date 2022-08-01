class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end()); 
        int min_diff = INT_MAX;          
        int ans = 0;                     
        for(int i =0; i < nums.size(); i++)
        {
            if((i>0) && nums[i] == nums[i-1]) continue;    
            int l = i+1, h = nums.size()-1;   
            while(l < h)
            {
                int final_sum = nums[i]+nums[l]+nums[h];      
                if(final_sum == target){          
                    return target;
                }
                if(abs(final_sum - target) < min_diff){     
                    min_diff = abs(final_sum - target);     
                    ans = final_sum;        
                } 
                if( l < h && final_sum > target) h--;       
                else if(l < h && final_sum < target) l++;            
            }
        }
        return ans;
    }
};