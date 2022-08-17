class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int> s;
        vector<string> list {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    for(string x:words){
        string str="";
        for(char c:x){
            str+=list[c-'a'];
        }
        s[str]=0;
    }
    return s.size();
    }
};