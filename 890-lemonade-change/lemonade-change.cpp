class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int cnt5=0,cnt10=0,cnt20=0;
        for(int i=0; i<n; i++){
            if(bills[i]==5){
                cnt5++;
                continue;
            }
            else if(bills[i]==10){
                if(cnt5>0){
                    cnt5--;
                    cnt10++;
                    continue;
                }else return false;
            }
            else if(bills[i]==20){
                //we have to return 15
                if(cnt10>0 && cnt5>0){
                    cnt10--;
                    cnt5--;
                    cnt20++;
                    continue;
                }else if(cnt5>=3){
                    cnt5-=3;
                    cnt20++;
                    continue;
                }else return false;
            }
        }
        return true;
    }
};