class Solution {
public: 
// let do some optimization
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;

        // lambda function
        auto expandAroundCenter = [&](int left, int right){
            while(left>=0 && right<n && s[left]==s[right]){
                cnt++;
                left--;
                right++;
            }
        };

        for(int i=0; i<n; i++){
            // for odd len  palindrome
            expandAroundCenter(i,i);
            //for even len palindrome
            expandAroundCenter(i,i+1);
        }

        return cnt;
    }
};