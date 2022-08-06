class Solution {
public:
       int n;
        void dfs(vector<vector<string>> &ans,string a,map<string,vector<pair<string,bool>>> &m,vector<string> &vec){
        if(ans.size()>0){
            return;
        }
        if(vec.size()==n+1){
            ans.push_back(vec);
            return;
        }
        
        for(int i = 0;i<m[a].size();i++){
            auto z = m[a][i];
            if(z.second){
                vec.push_back(z.first);
                m[a][i] = {z.first,false};
                dfs(ans,z.first,m,vec);
                vec.pop_back();
                m[a][i] = {z.first,true};
            }
            
        }
       
    }
    vector<string> findItinerary(vector<vector<string>>& tick) {
        map<string,vector<pair<string,bool>>> m;
        for(auto x:tick){
            m[x[0]].push_back({x[1],true});
        }
        for(auto x:m){
            vector<pair<string,bool>> ve = x.second;
            sort(ve.begin(),ve.end());
            m[x.first] = ve;
        }
        n = tick.size();
        map<string,bool> vis;
        vector<vector<string>> ans;
        vector<string> vec;
        vec.push_back("JFK");
        dfs(ans,"JFK",m,vec);
        return ans[0];
    }
};