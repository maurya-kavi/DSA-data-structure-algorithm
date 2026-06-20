class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        if(k==n) return 1;
        int ans=1;
        int i=k;
        while(i<n){
            bool valid=true;
            int ii=i;
            for(int j=0; j<n; j++){
                if(ii>=n) break;
                if(word[j]!=word[ii]) {
                    valid=false;
                    break;
                }
                ii++;
            }
            if(ii>=n) break;
            if(!valid) ans++;
            i+=k;
        }
        return ans;
    }
};