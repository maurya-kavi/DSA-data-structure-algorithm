class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.size();
        vector<int>ans(n,0);
        long long curr_rem=0;
        for(int i=0; i<n; i++){
            int val=word[i]-'0';
            curr_rem=(curr_rem*10+val)%m;
            if(curr_rem==0) ans[i]=1;
        }
        return ans;
    }
};