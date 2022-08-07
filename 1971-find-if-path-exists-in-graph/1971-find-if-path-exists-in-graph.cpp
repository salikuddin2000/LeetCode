class Solution {
    vector<int> parent;
public:
    int find_set(int v){
        if(v==parent[v]) return v;
        return parent[v]=find_set(parent[v]);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0;i<n;i++) parent.push_back(i);
        for(auto itr:edges){
            parent[find_set(itr[0])]=find_set(itr[1]);
        }
        return find_set(source)==find_set(destination);
    }
};