class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return false;
        if(s[0]==t[0]) return isSubsequence(s.substr(1),t.substr(1));
        return isSubsequence(s,t.substr(1));
    }
};