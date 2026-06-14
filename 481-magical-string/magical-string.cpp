class Solution {
public:
    int magicalString(int n) {
        int cnt1=0;
        if(n<=3) return 1;
        cnt1++;
        // initalise with 1,2,2 reader is at index 2
        vector<int>v;
        v.insert(v.end(),{1,2,2});
        int reader=2; // reader index
        while(v.size()<n){
            if(v.back()==1){
                // grouping is alternate so push 2 v[reader] times
                if(v[reader]==1){
                    v.push_back(2);
                }
                else{
                    v.push_back(2);
                    v.push_back(2);
                }
            }else{
                if(v[reader]==1){
                    v.push_back(1);
                    cnt1+=1;
                }
                else{
                    v.push_back(1);
                    cnt1++;
                    v.push_back(1);
                    if(v.size()<=n) cnt1++;
                }
            }
            reader++;
        }
        return cnt1++;
    }
};