class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long int> st;
        st.insert(1);

        vector<long long int>v(n);
        int i=0;
    
        while(!st.empty()){
            auto it=st.begin();
            long long int x=*it;
            st.erase(it);
            v[i++]=x;
            if(i==n) break;
            st.insert(x*2);
            st.insert(x*3);
            st.insert(x*5);
        }
        return v[n-1];
    }
};