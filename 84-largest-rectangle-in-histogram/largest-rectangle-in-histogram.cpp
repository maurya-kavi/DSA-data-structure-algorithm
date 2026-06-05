class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>v_nse=nse(heights);
        vector<int>v_pse=pse(heights);
        int ans=0;
        for(int i=0; i<n; i++){
            int width=(v_nse[i]-i) + (i-v_pse[i]) - 1;
            int val=width*heights[i];
            ans=max(ans,val);
        }
        return ans;
    }

    vector<int>nse(vector<int>&heights){
        // find the next smaller element for each elements
        int n=heights.size();
        stack<pair<int,int>>s;
        vector<int>v_nse(n); // store the indics for each element of their next smaller element
        v_nse[n-1]=n; 
        s.push({heights[n-1],n-1});
        for(int i=n-2; i>=0; i--){
            while(!s.empty() && s.top().first>=heights[i]) s.pop();
            if(!s.empty()) v_nse[i]=s.top().second;
            else v_nse[i]=n;
            s.push({heights[i],i});
        }
        return v_nse;
    }

    vector<int>pse(vector<int>&heights){
        int n=heights.size();
        stack<pair<int,int>>s;
        vector<int>v_pse(n);
        v_pse[0]=-1;
        s.push({heights[0],0});
        for(int i=1; i<n; i++){
            while(!s.empty() && s.top().first>=heights[i]) s.pop();
            if(!s.empty()) v_pse[i]=s.top().second;
            else v_pse[i]=-1;
            s.push({heights[i],i});
        }
        return v_pse;
    }
};