class Node{
            public:
            bool end;
            Node* next[26];
            Node(){
                end=false;
                for(int i=0;i<26;i++){
                    next[i]=NULL;
                }
            }
        };
class Trie : public Node{
    public:
        
        Node* trie;
        Trie(){
            trie=new Node();
        }
        void insert(string word){
                int i=0;
                Node* it=trie;
                while(i<word.size()){
                    if(it->next[word[i]-'a']==NULL){
                        it->next[word[i]-'a']=new Node();
                    }
                    it=it->next[word[i]-'a'];
                    i++;
                }
                it->end=true;
        }
        bool search(string word){
            int i=0;
            Node* it=trie;
            while(i<word.size()){
                if(it->next[word[i]-'a']==NULL) return false;
                it= it->next[word[i]-'a'];
                i++;
            }
            return it->end;
        }
};
class Solution : public Trie{
    Trie* dictionary= new Trie();
public:
    bool helper(string s,int n,vector<int> &dp){
        if(n==0) return true;
        if(dp[n]!=-1) return dp[n]==1?true:false;
        if(dictionary->search(s)) return dp[n]=true;
        string str="";
        bool ans;
        for(int i=0;i<n;i++){
            str+=s[i];
            ans=dictionary->search(str)&&helper(s.substr(i+1),n-i-1,dp);
            if(ans) return dp[n]=true;
        }
        return dp[n]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string w:wordDict) dictionary->insert(w);
        int n=s.size();
        vector<int> dp(n+1,-1);
        return helper(s,s.size(),dp);
    }
};