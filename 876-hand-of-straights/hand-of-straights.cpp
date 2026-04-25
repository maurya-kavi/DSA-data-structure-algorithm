class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        unordered_map<int,int>mp;
        for(int num:hand) mp[num]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto [key,val]:mp){
            pq.push({key,val});
        }
        while(!pq.empty()){
            vector<pair<int,int>>temp;
            int val=pq.top().first;
            int freq=pq.top().second;
            pq.pop();
            int m=groupSize;
            m--;
            freq--;
            if(freq>0) temp.push_back({val,freq});
            while(m>0 && !pq.empty()){
                int vall=pq.top().first;
                int freqq=pq.top().second;
                pq.pop();
                if(abs(val-vall)>1) return false;
                freqq--;
                val=vall;
                if(freqq>0) temp.push_back({vall,freqq});
                m--;
            }
            if(m>0) return false;
            for(auto [f,s]:temp){
                pq.push({f,s});
            }
        }
        return true;
    }
};