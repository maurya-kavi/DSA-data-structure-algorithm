class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int>mp;
        int ans=0;
        int score=0;
int n=hours.size();

        for(int i=0; i<n; i++){
            if(hours[i]>8) score++;
            else score--;

            if(score>0) ans=max(ans, i+1);
            else{
                if(mp.find(score)==mp.end()){
                    mp[score]=i;
                }

                if(mp.find(score-1)!=mp.end()){
                    ans=max(ans, i-mp[score-1]);
                }
            }
        }

        return ans;
    }
};


// naive approach 
/*
int n=hours.size();
        vector<int>a(n);
        for(int i=0; i<n; i++){
            if(hours[i]>8) a[i]=1;
            else a[i]=-1;
        }

        vector<int>pre(n,0);
        for(int i=0; i<n; i++){
            if(i==0) pre[i]=a[i];
            else pre[i]=pre[i-1]+a[i];
        }
int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                int sum=pre[i];
                if(j>0) sum-=pre[j-1];
                if(sum>0) ans=max(ans,i-j+1);
            }
        }
return ans;
*/