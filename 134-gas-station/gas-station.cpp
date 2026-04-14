class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalGasReq=0;
        int totalGasAvail=0;
        for(int i=0; i<n; i++){
            totalGasReq+=cost[i];
            totalGasAvail+=gas[i];
        }
        if(totalGasAvail<totalGasReq) return -1;

        int start=0;
        int yourTank=0;
        for(int i=start; i<n; i++){
            yourTank+=gas[i]-cost[i];

            if(yourTank<0){
                start=i+1;
                yourTank=0;
            }
        }
        return start;
    
    }
};