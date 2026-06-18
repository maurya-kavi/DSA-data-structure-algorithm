class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int u=55;
        vector<unordered_map<int,int>>r(u);
        vector<multiset<int>>p(u);

        int n = nums.size();
        vector<vector<int>>dp(n+5,vector<int>(k+5,1));
        for(int i=0; i<n; i++){  
            for(int j=k; j>=0; j--){
                int o1=r[j][nums[i]]+1;
                int o5=0;
                if(j!=0){
                    int y=r[j-1][nums[i]];
                    if(y!=0){
                        int g5=p[j-1].size();
                        if(g5>=2){
                            auto itr=p[j-1].end();
                            --itr;
                            o5=(*itr);
                            if(o5==y){
                                --itr;
                                o5=(*itr);
                            }
                        }
                    }
                    else{
                        int g5=p[j-1].size();
                        if(g5!=0){
                            auto itr=p[j-1].end();
                            --itr;
                            o5=(*itr);
                        }
                    }
                }
                dp[i][j]=max(o1,o5+1);
                r[j][nums[i]]=dp[i][j];
                p[j].insert(dp[i][j]);
            }
        }
        int g=0;
        for(int i=0; i<n; i++){
            int x=dp[i][k];
            g=max(g,x);
        }
        return g;
        
    }
};

