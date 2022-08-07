class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outDeg(n+1,0);
        vector<int> inDeg(n+1,0);
        for(auto itr: trust){
            outDeg[itr[0]]++;
            inDeg[itr[1]]++;
        }
        for(int i=1;i<n+1;i++) if(outDeg[i]==0 && inDeg[i]==n-1) return i;
        return -1;
    }
};