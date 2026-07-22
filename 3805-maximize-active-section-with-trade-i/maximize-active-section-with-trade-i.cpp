class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t="1"+s+"1";
        int n=t.size();
        vector<int>cnt0;
        int cnt=0;
        int cnt1=0;
        for(int i=0; i<n; i++){
            if(t[i]=='0') cnt++;
            else {
                if(cnt>0) cnt0.push_back(cnt);
                cnt=0;
                cnt1++;
            }
        }
cnt1-=2;
        int m=cnt0.size();
        // if(m==1) return cnt1+cnt0[0]; // if only one block of zero then ans would be simply cnt1;
        int mxpairsum=0;
        for(int i=1; i<m; i++){
mxpairsum=max(mxpairsum,cnt0[i]+cnt0[i-1]);
        }

        return mxpairsum+cnt1;
    }
};