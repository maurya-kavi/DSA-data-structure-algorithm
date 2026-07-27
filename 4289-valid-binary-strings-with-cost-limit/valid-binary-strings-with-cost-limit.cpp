class Solution {
public:
vector<string>ans;
    vector<string> generateValidStrings(int n, int k) {
        string curr="";
        solve(0,n,k,curr);
        return ans;
    }

    void solve(int i,int n, int k, string &curr){
        if(i==n){
            ans.push_back(curr);
            return;
        }

        // take with 1
        curr+='1';
        if(i==0 || (k-i>=0 && curr[i-1]!='1')) solve(i+1,n,k-i,curr);

        curr.pop_back();

        curr+='0';
        solve(i+1,n,k,curr);
        curr.pop_back();
    }
};