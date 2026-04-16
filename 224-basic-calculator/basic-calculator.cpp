class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long result = 0;
        long long num = 0;
        int sign = 1;

        for(char c : s) {
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if(c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if(c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if(c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(c == ')') {
                result += sign * num;
                num = 0;

                result *= st.top(); st.pop();
                result += st.top(); st.pop();
            }
        }

        result += sign * num;
        return (int)result;
    }
};