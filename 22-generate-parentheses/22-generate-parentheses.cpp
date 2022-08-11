class Solution {
public:
vector<string> ans;
void gen(string s, int n, int o, int c){
    if(o == n && c == n){
        ans.push_back(s);
        return;
    }
    
    if(o < n) {
        gen(s+"(", n, o+1, c);            
    }
    
    if(o > 0 && c < n && c < o){
        gen(s+")", n, o, c+1);            
    }
    
}
vector<string> generateParenthesis(int n) {
    gen("",n,0,0);
    return ans;
}
};