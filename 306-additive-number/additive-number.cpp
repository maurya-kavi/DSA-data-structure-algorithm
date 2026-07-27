class Solution {
public:
    string add(string &a, string &b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, c = 0;

        while (i >= 0 || j >= 0 || c) {
            int x = (i >= 0) ? a[i--] - '0' : 0;
            int y = (j >= 0) ? b[j--] - '0' : 0;
            int s = x + y + c;
            res.push_back(char('0' + (s % 10)));
            c = s / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string &num, int i, int j) {
        string a = num.substr(0, i);
        string b = num.substr(i, j - i);

        int k = j;

        while (k < num.size()) {
            string c = add(a, b);

            if (k + c.size() > num.size())
                return false;

            if (num.compare(k, c.size(), c) != 0)
                return false;

            k += c.size();
            a = b;
            b = c;
        }

        return true;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i <= n - 2; i++) {
            if (num[0] == '0' && i > 1)
                break;

            for (int j = i + 1; j <= n - 1; j++) {
                if (num[i] == '0' && j - i > 1)
                    break;

                if (check(num, i, j))
                    return true;
            }

        }

        return false;
    }
};