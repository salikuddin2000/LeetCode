class Solution {
public:
    bool bipart;
    void color(int u,int curr,vector<vector<int>>& graph,vector<int> &col,vector<bool> &vis){
        if(col[u]!=-1 and col[u]!=curr){
            bipart=false;
            return;
        }
        col[u]=curr;
        if(vis[u])return;
        vis[u]=true;
        for(auto i:graph[u]){
            color(i,curr xor 1,graph,col,vis);
        }
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        vector<bool> vis(n,false);
        int tempColor;
        bipart=true;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                color(i,0,graph,col,vis);
            }
        }
        return bipart;
    }
};