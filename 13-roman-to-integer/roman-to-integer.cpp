class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int i=n-1;
        vector<int>arr(n);
        while(i>=0){
            int a=0;
            if(s[i]=='I') a=1;
            else if(s[i]=='V') a=5;
            else if(s[i]=='X') a=10;
            else if(s[i]=='L') a=50;
            else if(s[i]=='C') a=100;
            else if(s[i]=='D') a=500;
            else if(s[i]=='M') a=1000;

            arr[i]=a;
            i--;
        }

        int ans=0;

        i=n-1;
        ans+=arr[i];
        i--;
        while(i>=0){
            if(arr[i]==arr[i+1]){
                ans+=arr[i];
            }
            else if(arr[i+1]>arr[i]){
                ans-=arr[i];
            }
            else if(arr[i]>arr[i+1]){
                ans+=arr[i];
            }
            i--;
        }
        return ans;
    }
};