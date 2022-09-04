class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), beauty=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;
                int maxi=INT_MIN, mini=INT_MAX;
                for(auto m:mp)
                {
                    maxi = max(maxi, m.second);
                    mini = min(mini, m.second);
                }
                beauty += maxi-mini;
            }
        }
        return beauty;
    }
};