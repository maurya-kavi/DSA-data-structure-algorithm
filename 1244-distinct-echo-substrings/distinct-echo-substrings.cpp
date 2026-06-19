class Solution {
public:

// naive approach, is to generate all the substring and check for the condition 
// 2nd approach we can use the rolling hash

    int distinctEchoSubstrings(string text) {
        int n=text.size();
        set<string>st;
        int cnt=0;
        for(int i=0; i<n; i++){
            string t="";
            for(int j=i; j<n; j++){
                t+=text[j];
                if((j-i+1)%2==0 && valid(t)) {
                    if(!st.count(t)){
                        st.insert(t);
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    bool valid(string &t){
        int m=t.size()/2;
        int l=0, r=m;
        while(l<m){
            if(t[l]!=t[r]) return false;
            l++; r++;
        }
        return true;
    }
};