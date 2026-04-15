class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        //optimization
        vector<int>premx(n);
        vector<int>sufmx(n);
        for(int i=0; i<n; i++){
            if(i==0) premx[i]=height[i];
            else premx[i]=max(premx[i-1],height[i]);
        }
        for(int i=n-1; i>=0; i--){
            if(i==n-1) sufmx[i]=height[i];
            else sufmx[i]=max(sufmx[i+1],height[i]);
        }
        int ans=0;
        for(int i=1; i<n-1; i++){
        //     int mxleft=INT_MIN, mxright=INT_MIN;
        //    for(int j=0; j<i; j++) mxleft=max(mxleft,height[j]);
        //    for(int j=i+1; j<n; j++) mxright=max(mxright,height[j]);

           int x=min(premx[i-1],sufmx[i+1]);
           if(height[i]>x) continue;
           else ans+=(x-height[i]);
        //    mxleft=INT_MIN,mxright=INT_MIN;
        }
        return ans;
    }
};