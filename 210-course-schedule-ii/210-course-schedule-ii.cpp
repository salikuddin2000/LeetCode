class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> inDeg(n,0);
        vector<int> ans;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            inDeg[it[0]]++;
        }
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(inDeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it:adj[temp]){
                inDeg[it]--;
                if(inDeg[it]==0) q.push(it);
            }
            ans.push_back(temp);
        }
        if(ans.size()==n) return ans;
        else return{};
    }
};