class Solution {
public:
#define ll long long
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        ll cnt_ans=0;
        int n=nums.size();
        vector<ll>cnt(n+1,0);
        cnt[0]=0;
        for(int i=1; i<=n; i++){
            cnt[i]=cnt[i-1]+(nums[i-1]%modulo==k? 1:0);
        }
        // now check for the how many indices j < i such that (count[i] - count[j]) % modulo == k.
        //(count[i] - count[j]) % modulo == k becomes 
        // count[j] = (count[i] + modulo - k) % modulo.

        unordered_map<int,int>mp;
        mp[0]=1; // count 0 would be there , Base case: The empty prefix has 0 interesting elements.
        for(int i=1; i<=n; i++){
            // iss i ke liye previously kon kon si j hai such that j se i ka subarray mein cnt%modulo ==k ;
            int curr_mod=cnt[i]%modulo;
            int target=(curr_mod + modulo - k) % modulo;
            if(mp.find(target)!=mp.end()){
                cnt_ans+=mp[target];
            }
            mp[curr_mod]++;
        }
        return cnt_ans;
    }
};