class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor=image[sr][sc];
        if(prevColor==color) return image;
        int n=image.size(),m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<pair<int,int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int cury=q.front().first;
            int curx=q.front().second;
            cout<<cury<<":"<<curx<<" ";
            q.pop();
            for(auto d:dirs){
                int y=cury+d.first;
                int x=curx+d.second;
                if(y>-1&&x>-1&&y<n&&x<m&&image[y][x]==prevColor){
                    q.push({y,x});
                }
            }
            image[cury][curx]=color;
        }
        return image;
    }
};