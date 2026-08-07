class Solution {
public:
using ll =long long;
    long long taskSchedulerII(vector<int>& tasks, int space) {
        ll m=tasks.size();
        unordered_map<ll,ll>mp;
        ll t=0;
        for(ll i=0; i<m; i++){
            if(!mp.count(tasks[i]) || (t-mp[tasks[i]]>space) ) {
                mp[tasks[i]]=t;
                t++;
            }else{
                ll gap=t-mp[tasks[i]]-1;
                ll rem=space-gap;
                t+=rem;
                mp[tasks[i]]=t;
                t++;
            }
            
        }
        return t;
    }
};