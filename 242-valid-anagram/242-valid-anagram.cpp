class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alph(26,0);
        if(s.length()!=t.length()) return false;
        for(char c:s) alph[c-'a']++;
        for(char c:t){
            if(alph[c-'a']==0) return false;
            else alph[c-'a']--;
        }
        return true;      
    }
};