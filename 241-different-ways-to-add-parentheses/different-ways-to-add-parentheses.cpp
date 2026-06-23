class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.size();
        return solve(0,n-1,expression);
    }

    vector<int> solve(int l,int r, string exp){
        vector<int>res;

        if(l==r){
            string t=exp.substr(l,r-l+1);
            int val=stoi(t);
            res.push_back(val);
            return res;
        }

        bool flag=true;
        for(int i=l; i<=r; i++){
            if(exp[i]=='-' || exp[i]=='+' || exp[i]=='*'){
                flag=false;
                vector<int>left=solve(l,i-1,exp);
                vector<int>right=solve(i+1,r,exp);

                for(auto lVal:left){
                    for(auto rVal:right){
                        int x=0;
                        if(exp[i]=='-') x=lVal-rVal;
                        else if(exp[i]=='+') x=lVal+rVal;
                        else if(exp[i]=='*') x=lVal*rVal;

                        res.push_back(x);
                    }
                }
            }
        }
        if(flag){
            // l se r tak val hai usko return kardo
            string t=exp.substr(l,r-l+1);
            int x=stoi(t);
            res.push_back(x);
            return res;
        }
        return res;
    }
};