class Solution {
public:
    vector<int> parent;
    vector<int> sz;
    
    void make_set(int n) {
        for(int i=0;i<n;i++) {
            parent[i]=i;
            sz[i]=1;
        }
    }
    
    int find_set(int a) {
      if(parent[a]==a)
          return a;
      return parent[a]=find_set(parent[a]);
    }
    void union_set(int a, int b) {
        a=find_set(a);
        b= find_set(b);
        if(a!=b) {
            if(sz[a]<sz[b]) 
              swap(a,b);
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      parent.assign(n,-1);
      sz.assign(n,0);
      make_set(n);
      for(int i=0;i<edges.size();i++) {
           int u = edges[i][0];
           int v = edges[i][1];
          int a = find_set(u);
          int b = find_set(v);
          if(a!=b) {
               union_set(u,v);
          }
      }
      int a = find_set(source);
      int b = find_set(destination);
      return a==b;
    }
};