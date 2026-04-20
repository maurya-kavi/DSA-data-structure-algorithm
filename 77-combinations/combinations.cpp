class Solution {
public:
    vector<vector<int>>result;
    

    void backtrack(int n, int k, int index, vector<int>&temp, vector<int>&num){
        //base case
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        //exit from recursion
        if(index==num.size()) return;
        temp.push_back(num[index]);
        backtrack(n,k,index+1,temp,num);
        temp.pop_back(); //backtrack

        //excluding curr element
        backtrack(n,k,index+1,temp,num);

    }
    vector<vector<int>> combine(int n, int k) {
        if(n<k) return {};
        vector<int>num(n);
        for(int i=0; i<n; i++){
            num[i]=i+1;
        }
        vector<int>temp;
        backtrack(n,k,0,temp,num);
        return result;
    }
};