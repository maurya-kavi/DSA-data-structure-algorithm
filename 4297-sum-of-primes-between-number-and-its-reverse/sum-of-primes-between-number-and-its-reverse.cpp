class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string s=to_string(n);
        string t=s;
        reverse(t.begin(),t.end());
        int m=s.size();
        for(int i=0; i<m; i++){
            if(t[i]!='0'){
                t=t.substr(i);
                break;
            }
        }
        int x=stoi(t);
        int l=min(x,n);
        int r=max(x,n);
        int ans=0;
        for(int i=l ; i<=r; i++){
            if(isPrime(i)) ans+=i;
        }
        return ans;
    }
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
};