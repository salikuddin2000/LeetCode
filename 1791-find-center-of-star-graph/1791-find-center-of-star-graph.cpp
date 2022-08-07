class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int count1=edges[0][0];
        int count2=edges[0][1];
        int freq1=0;
        int freq2=0;
        for(auto itr:edges){
            if(itr[0]==count1) freq1++;
            if(itr[1]==count2) freq2++;
        }
        if(freq2>freq1) return count2;
        else return count1;
    }
};