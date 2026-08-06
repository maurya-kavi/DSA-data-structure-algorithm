class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>fre(26,0);
        for(char ch:tasks) fre[ch-'A']++;

        priority_queue<pair<int,int>>pq;
        queue<tuple<int,int,int>>q; //tm,fre,char
        for(int i=0; i<26; i++){
            if(fre[i]!=0){
                pq.push({fre[i],i});
            }
        }
int tm=0;
        while(!pq.empty() || !q.empty()){
            if(!q.empty()){
                auto [t,f,i]=q.front();
                if(tm==t){
                    q.pop();
                    pq.push({f,i});
                }
            }

            if(!pq.empty()){
                auto [f,i]=pq.top();
                pq.pop();
                if(f-1>0) q.push({tm+n+1,f-1,i});
            }
            tm++;
        }
        return tm;
    }
};