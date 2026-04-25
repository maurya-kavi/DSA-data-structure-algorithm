class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        priority_queue<int>pq; //max-heap
        int sz=tasks.size();
        for(char ch:tasks){
            mp[ch]++;
        }
        for(auto [key,val]:mp){
            pq.push(val); // freq, char
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            int cycle=n+1;
            int i=0;
            while(i<cycle && !pq.empty()){
                int cnt=pq.top();
                pq.pop();
                cnt--;
                if(cnt>0){
                    temp.push_back(cnt);
                }
                time++;
                i++;
            }
            for(int num:temp){
                pq.push(num);
            }
            if(pq.empty()) break;

            time+=(cycle-i);
        }
        return time;
    }
};