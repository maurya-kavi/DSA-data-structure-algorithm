class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        bool found=false;
        for(int i=1; i<n-1; i++){
            bool isInc=true;
            for(int j=1; j<=i; j++){
                if(arr[j]<=arr[j-1]) {isInc=false; break;}
            }
            if(isInc){
            for(int j=i; j<n-1; j++){
                if(arr[j]<=arr[j+1])  break;
                if(j==(n-2)) found=true;
            }
            }
            if(found) break;
        }
        if(found) return true;
        return false;
    }
};