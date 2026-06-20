class Solution {
    #define ull unsigned long long
    const ull p=1000003;
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        int m=pattern.size();
        int ans=0;
        if(n<=m) return 0;
        vector<int> s(n - 1);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] > nums[i]) s[i] = 1;
            else if (nums[i + 1] == nums[i]) s[i] = 0;
            else s[i] = -1;
        }
        
        ull targetHash = 0;
        ull currHash = 0;
        ull hp = 1;
        
        for (int i = 0; i < m - 1; i++) {
            hp *= p;
        }
        
        for (int i = 0; i < m; i++) {
            targetHash = targetHash * p + (pattern[i] + 2);
            currHash = currHash * p + (s[i] + 2);
        }
        
        if (currHash == targetHash) ans++;
        
        for (int i = m; i < n - 1; i++) {
            currHash = currHash - (s[i - m] + 2) * hp;
            currHash = currHash * p + (s[i] + 2);
            
            if (currHash == targetHash) {
                ans++;
            }
        }
        
        return ans;
    }
};