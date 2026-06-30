class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>a(n);
        for(int i=0; i<n; i++){
            a[i]=i+1;
        }

        sort(a.begin(),a.end(),comp);

        return a;
    }

    static bool comp( const int &a, const int &b){
        string p=to_string(a);
        string q=to_string(b);

        return p<q;
    }
};