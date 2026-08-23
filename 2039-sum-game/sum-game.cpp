class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int d = 0;
        int q = 0;
        
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') q++;
            else d += num[i] - '0';
        }
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') q--;
            else d -= num[i] - '0';
        }
        
        if (q % 2 != 0) return true;
        return d + (q / 2) * 9 != 0;
    }
};