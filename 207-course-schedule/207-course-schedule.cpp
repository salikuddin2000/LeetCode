const int N=1e5+6;
class Solution {
    vector<int> parent= std:: vector<int>(N);
    vector<int> sz=std:: vector<int>(N);
public:
    bool is_cycle(int src,vector<int> &stack,vector<bool> &vis, vector<vector<int>> &adj){
        stack[src]=true;
        if(!vis[src]){
            vis[src]=true;
            for(auto it:adj[src]){
                if(!vis[it] and is_cycle(it,stack,vis,adj)) return true;
                if(stack[it]) return true;
            }
        }
        stack[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses+1);
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> stack(numCourses+1,0);
        vector<bool> vis(numCourses+1,0);
        for(int i=0;i<numCourses+1;i++){
            if(!vis[i] and is_cycle(i,stack,vis,adj)) return false;
        }
        return true;
    }
};