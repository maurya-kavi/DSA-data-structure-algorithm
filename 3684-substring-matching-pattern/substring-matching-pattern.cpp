class Solution {
public:
    bool hasMatch(string s, string p) {

        int ind = p.find('*');

        string s1 = p.substr(0, ind);
        string s2 = p.substr(ind + 1);

        int pos = 0;

        // find s1 first
        if (!s1.empty()) {
            pos = s.find(s1);
            if (pos == string::npos) return false;
        } else {
            pos = 0;
        }

        // find s2 after s1
        if (!s2.empty()) {
            pos = s.find(s2, pos + s1.size());
            if (pos == string::npos) return false;
        }

        return true;
    }
};