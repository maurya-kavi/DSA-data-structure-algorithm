class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int>s;
        vector<int>ans(n);
        ans[n-1]=prices[n-1];
        s.push(prices[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!s.empty() && s.top()>prices[i]) {
                s.pop();
            }
            ans[i]=prices[i];
            if(!s.empty()) ans[i]-=s.top();
            s.push(prices[i]);
        }
        return ans;
    }
};