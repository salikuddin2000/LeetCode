class Solution {
    vector<int> parent= std::vector<int> (1e5);
    vector<bool> vis= std::vector<bool> (1e5);
    vector<int> sz= std::vector<int> (1e5);
public:
    void make_set(int a){
        parent[a]=a;
        sz[a]=1;
    }
    int find_set(int a){
       if(a==parent[a]) return a;
        else return parent[a]=find_set(parent[a]);
    }
    void join(int a,int b){
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        for(int i=0;i<n;i++) make_set(i);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isConnected[i][j]){
                    int a=find_set(i);
                    int b=find_set(j);
                    if(a!=b) join(a,b);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            int a=find_set(i);
            if(!vis[a]){
                count++;
                vis[a]=true;
            }
        }
        return count;
    }
};