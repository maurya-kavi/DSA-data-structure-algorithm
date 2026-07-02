class Solution {
public:
    int longestWPI(vector<int>& hours) {
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
    }
};