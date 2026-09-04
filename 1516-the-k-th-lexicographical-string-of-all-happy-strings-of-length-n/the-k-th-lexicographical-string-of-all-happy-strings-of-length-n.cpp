class Solution {
public:

// brute force is generate all the string with condition tha curr char is not same as the previous char

vector<string >v;

    string getHappyString(int n, int k) {
        
        string s="";
        char prev='{';
        solve(n,s, prev);

        sort(v.begin(), v.end());

        if(v.size() < k) return {};

        return v[k-1];
    }

    void solve(int &n, string &s, char prev){

        if(s.size()==n) {
            v.push_back(s);
            return;
        }

        if(prev!='a') {
            s+='a';
            solve(n, s, 'a');
            s.pop_back();
        }

        if(prev!='b'){
             s+='b';
            solve(n, s, 'b');
            s.pop_back();
        }

        if(prev!='c'){
            s+='c';
            solve(n, s, 'c');
            s.pop_back();
        }


    }
};