class Solution {
public:
void dfs(int node, vector<bool>& visited,vector<int> adj[]){
    visited[node]=true;
    
    for(auto nbr : adj[node]){
        if(!visited[nbr])
            dfs(nbr,visited,adj);
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    int ans=0;
    vector<int> adj[n];
    vector<bool> visited(n,0);
    if(connections.size() < n-1){
        return -1;
    }
    
    for(auto i:connections){
        adj[i[0]].push_back(i[1]);
         adj[i[1]].push_back(i[0]);
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            ans++;
            dfs(i,visited,adj);
        }
    }
    
    return ans-1;
}
};