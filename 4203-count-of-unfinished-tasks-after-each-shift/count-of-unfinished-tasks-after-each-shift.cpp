class Solution {
public:
using ll=long long;
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int m=shifts.size();
        int n=tasks.size();
        vector<ll>preSum(n,0);
        for(ll i=0; i<n; i++){
            if(i==0) preSum[i]=tasks[i];
            else preSum[i]=preSum[i-1]+tasks[i];
        }

        vector<int>ans;
        ans.reserve(m);
        ll i=0;
        
        ll carryTime=0;
        for(int j=0; j<m; j++){
            ll t=shifts[j]+carryTime;
            ll tttcar=preSum[n-1];   //timetakentocompallrem
            if(i>0) tttcar-=preSum[i-1];

            if(t>=tttcar){
                ans.push_back(0);
                carryTime=0;
                i=0;
            }
            else if(t<tasks[i]){
                ans.push_back(n-i); //n-i unfinished tasks
                carryTime=t;
            }
            else{
                //binary search 
                // kis ith tak complete kiyaa jaa sakta hai
                ll l=i;
                ll h=n-1;
int icanbe=i;
                while(l<=h){
                    ll mid=l+(h-l)/2;
                    ll timereq=preSum[mid];
                    if(i>0) timereq-=preSum[i-1];
                    if(timereq<=t){
                        icanbe=mid;
                        l=mid+1;
                    }else h=mid-1;
                }
                

                ll timeTaken=(preSum[icanbe]);
                if(i>0) timeTaken-=preSum[i-1];

                carryTime=(t-timeTaken);

                i=icanbe+1;
                ans.push_back(n-i);
            }
            
        }
        return ans;
    }
};