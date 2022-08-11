class Solution {
    int size;
public:
    vector<string> helper(int sz,int open,int close){
        if(sz==2*size) return{""};
        // string str="";
        vector<string> ans;
        if(open==close) {
            vector<string> v=helper(sz+1,open+1,close);
            for(auto itr:v){
                ans.push_back("("+itr);
            }
        }
        else{
            if(open<size){
                vector<string> op=helper(sz+1,open+1,close);
                for(auto itr:op){
                    ans.push_back("("+itr);
                }
            }
            vector<string> cl=helper(sz+1,open,close+1);
            for(auto itr:cl){
                ans.push_back(")"+itr);
            }
        }
        return ans;

    }
    vector<string> generateParenthesis(int n) {
        size=n;
        return helper(0,0,0);
    }
};