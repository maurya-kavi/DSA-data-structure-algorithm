class Solution {
public:


// lets optimise it , ab lexicographically hi generate karwate hain and k tak hi karwayenge and kth ko return kar denge;

    string ans;
    
    string getHappyString(int n, int k) {
        string s = "";
        char prev = '{';
        solve(n, s, prev, k);
        return ans;
    }

    void solve(int &n, string &s, char prev, int &k) {

        if(s.size() == n) {
            k--;

            if(k == 0)
                ans = s;

            return;
        }

        if(prev != 'a' && ans == "") {
            s += 'a';
            solve(n, s, 'a', k);
            s.pop_back();
        }

        if(prev != 'b' && ans == "") {
            s += 'b';
            solve(n, s, 'b', k);
            s.pop_back();
        }

        if(prev != 'c' && ans == "") {
            s += 'c';
            solve(n, s, 'c', k);
            s.pop_back();
        }
    }
};