class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(!st.empty()){
                if(s[i]=='(') st.push(s[i]);
                else st.pop();
                if(!st.empty())ans+=s[i];
            }
            else{
                st.push(s[i]);
            }
        }
        return ans;
    }
};