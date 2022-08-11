class Solution {
public:
    vector<string> helper(string digits){
        if(digits=="") return {""};
        int n= digits[0]-'0';
        int x=3;
        if(n==7||n==8) x=4;
        if(n==9) x=5;
        int i=1;
        if(n>7)i=2;
        vector<string> ans;
        vector<string> str=helper(digits.substr(1));
        for(; i<=x; i++){
            char c='a'+(n-2)*3+i-1;
            for(auto it:str){
                string res= c+it;
                ans.push_back(res);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        else return helper(digits);
    }
};