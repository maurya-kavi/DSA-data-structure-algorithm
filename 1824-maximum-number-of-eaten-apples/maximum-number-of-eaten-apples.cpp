class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n=apples.size();
        int day=1;
        int eaten=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0; i<n; i++){
            int good_till=i+days[i];
            if(apples[i]!=0 && days[i]!=0) pq.push({good_till,apples[i]});
            while(!pq.empty() && pq.top().first<(day)) pq.pop();
            if(!pq.empty()){
                auto [dayss,cnt]=pq.top();
                pq.pop();
                eaten++;
                cnt--;
                if(cnt>0) pq.push({dayss,cnt});
            }
            day++;
        }

        while(!pq.empty()){
            while(!pq.empty() && pq.top().first<(day)) pq.pop();
            if(!pq.empty()){
                auto [dayss,cnt]=pq.top();
                pq.pop();
                eaten++;
                cnt--;
                if(cnt>0) pq.push({dayss,cnt});
            }
            day++;
        }
        return eaten;
    }
};