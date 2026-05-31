class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        // if condition statisfy then ek hi free copy liya jayega by i and for the one time only by that i;
        int  n=items.size();
        int mnp=INT_MAX;
        // constraint given 1 <= factori <= items.length
        vector<int>freq(n+1,0);
        for(int i=0; i<n; i++){
            int fi=items[i][0];
            int p=items[i][1];
            mnp=min(mnp,p);
            freq[fi]++;
        }

        // ab factors ka multiples find karo ki kitna hai
        vector<int>multiples(n+1,0);
        for(int i=1; i<=n; i++){
            if(freq[i]==0) continue; 
            for(int j=i; j<=n; j+=i){
                multiples[i]+=freq[j];
            }
        }
        int usefulbuying=2*mnp;
        sort(items.begin(),items.end(), [](const auto &a, const auto&b){
            return a[1]<b[1]; // ascending order by price of items
        });
        int ans=0;
        for(int i=0; i<n; i++){
            int fi=items[i][0];
            int p=items[i][1];
            if(p>usefulbuying) break;
            if(p<=usefulbuying && multiples[fi]>=2 ){
                if(budget-p <0) break;
                int x=multiples[fi];
                x--;
                // x no of j hai toh max x bar buy karna will be good , if in budget
                if(1LL*x*p <= budget){
                    ans+=(2*x);
                    budget-=(x*p);
                }else{
                    int noofTimesCanBuy=budget/p;
                    ans+=(2*noofTimesCanBuy);
                    budget-=(p*noofTimesCanBuy);
                }
            
            }
        }
        if(budget>0) ans+=(budget/mnp);
        return ans;
    }
};