class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt=0;
        int n=digits.size();
        set<int>st;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                for(int k=0; k<n; k++){
                    if(k==i || k==j) continue;
                    if(digits[i]==0) continue;
                    if(digits[k]%2==0){
                        string s=to_string(digits[i]) + to_string(digits[j]) + to_string(digits[k]);
                        int x=stoi(s);
                        st.insert(x);
                    }
                }
            }
        }
        return st.size();
    }
};