class Solution {
public:
vector<int>ans;
long long diff=LLONG_MAX;
vector<int>factor;
unordered_set<long long>st;
    vector<int> minDifference(int n, int k) {
        
        // find all the factors of n 
        for(int i=1; i<=sqrt(n); i++){
            if(n%i==0) {
                factor.push_back(i);
                st.insert(i);
            }
            if(n/i != i){
                factor.push_back(n/i);
                st.insert(n/i);
            }
        }

vector<int>curr;
        solve(0,n,k, curr,1);

        return ans;
    }

    void solve(int i, int n, int k, vector<int>&curr,long long product){
       
        if(curr.size()==k){
            if(product!=n) return;
            auto it=minmax_element(curr.begin(), curr.end());
            if(diff>1LL*(*it.second-*it.first)){
                diff=1LL*(*it.second-*it.first);
                ans=curr;
            }
            return;
        }
        if(i>=factor.size()) return;

        // now apply unbounded knapsack
        curr.push_back(factor[i]);
        if(product*1LL*factor[i]<=n && st.count(product*1LL*factor[i])){
            solve(i,n,k,curr,product*1LL*factor[i]);
        }
        curr.pop_back();

        solve(i+1,n,k,curr,product);
    }
};