class Solution {
public:
vector<string>ans;
int n;
    vector<string> restoreIpAddresses(string s) {
        n=s.size();
        if(n>12 || n<4) return {};
        string curr="";
        solve(s,0,0,curr);
        return ans;
    }

    void solve(string&s, int ind, int part, string curr){
        if(ind==n && part==4){
            if(curr.size()>0) curr.pop_back(); // remove the last . that had been put in the rec call
            ans.push_back(curr);
            // curr+=".";
            return ;
        }
        if(ind<n & part>=4) return;
        if(ind>=n) return;

        if(ind<n){
            int val=stoi(s.substr(ind,1));
            if(val<=255){
                solve(s,ind+1,part+1,curr+s.substr(ind,1)+".");
                // curr.pop_back();
                // curr.pop_back();
            }
        }
        if(ind+1<n){
            int val=stoi(s.substr(ind,2));
            if(s[ind]!='0' && val<=255){
                solve(s,ind+2,part+1,curr+s.substr(ind,2)+".");
                                // curr.pop_back();
                                // curr.pop_back();
                                // curr.pop_back();

            }
        }
        if(ind+2<n){
            int val=stoi(s.substr(ind,3));
            if(s[ind]!='0' && val<=255){
                solve(s,ind+3,part+1,curr+s.substr(ind,3)+".");
                // curr.pop_back();
                                // curr.pop_back();
                                // curr.pop_back();
                                // curr.pop_back();
            }
        }
        
        
    }
};