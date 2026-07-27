class Solution {

public:
int n;
    unordered_set<string> sett;

    bool validParentheses(string& curr) {
        int op=0;
        for(int i=0; i<curr.size();i++){
            if(curr[i]=='(') op++;
            else if(curr[i]==')'){
                if(op<=0) return false;
                op--;
            }
        }
        return op==0? true:false;
    }

    int mxl = 0;
    void getall(string& s, int i, string &curr,  int bal) {
        if(bal<0 || bal>(n-i)) return;
        if (curr.size() + (n - i) < mxl)
            return;
        if (i == n) {
            if (!validParentheses(curr))
                return;

            if (curr.size() > mxl) {
                mxl = curr.size();
                sett.clear();
                sett.insert(curr);
            } else if (curr.size() == mxl) {
                sett.insert(curr);
            }

            return;
        }

        // take
        curr+=s[i];
        int x=0;
        if(s[i]=='(') x++;
        else if(s[i]==')') x--;

        getall(s, i + 1, curr,bal+x);
        curr.pop_back();
        
        // nottake
        getall(s, i + 1, curr,bal);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();

        // brute force
        /*
        generate all the parentheses using recursion( take or nottake ) then
        look for the valid parentheses and in all thosse valid parentheses just
        store those having min no of invalid parentheses removed and return it
        */

        /*
        got the MLE , noww we just have to store the valid parentheses having
        minimal removal there.........
        */
        /* more optimization of memory using backtracking and optimizing validparentheses chack function*/
        /* got tle now: apply yhe valid parentheses check in the recusive function too*/

        string curr = "";
        getall(s, 0, curr,0);

        return vector<string>(sett.begin(), sett.end());
    }
};