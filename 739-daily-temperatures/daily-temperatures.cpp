class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        ans[n-1]=0;
        stack<pair<int,int>>s;
        s.push({temperatures[n-1],n-1});
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top().first<=temperatures[i]) s.pop();
            if(!s.empty()) ans[i]=(s.top().second - i);
            else ans[i]=0;
            s.push({temperatures[i],i});
        }
        return ans;
    }
};