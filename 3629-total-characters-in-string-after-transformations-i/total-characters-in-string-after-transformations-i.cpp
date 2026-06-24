class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        if(t==0) return s.size();
        vector<int>prev(26,0);
        const int mod=1e9+7;
        for(char &ch:s){ prev[ch-'a']++;}

       
        for(int i=0; i<t; i++){
            vector<int>curr(26,0);
            for(int i=0; i<26; i++){
                if(i==25){
                    if(prev[i]>0){
                        curr[0]=(curr[0]+prev[i])%mod;
                        curr[1]=(curr[1]+prev[i])%mod;
                    }
                    continue;
                }
                int fre=prev[i];
                if(fre>0){
                    curr[i+1]=(curr[i+1]+fre)%mod;
                }
            }
            prev=curr;
        }
        
        int ans=0;
        for(int i=0; i<26; i++){
            ans=(ans+prev[i])%mod;
        }

        return ans;
    }
};