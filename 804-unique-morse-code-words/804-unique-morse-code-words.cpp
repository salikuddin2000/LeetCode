class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        vector<string> list {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    for(string x:words){
        string str="";
        for(char c:x){
            str+=list[c-'a'];
        }
        s.insert(str);
    }
    return s.size();
    }
};