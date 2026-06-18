class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (double) hour;
        double m = (double) minutes;

        double minInhr=(double)m/60.0;
        h+=minInhr;
        m=m/5;

        double gap01=abs(h-m)*30;
        double gap02=360.0-gap01;
        double ans=gap01;
        if(ans>gap02) ans=gap02;
        return ans;

    }
};