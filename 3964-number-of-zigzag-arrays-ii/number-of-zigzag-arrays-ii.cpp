class Solution {
    using ll = long long;
    using Matrix = vector<vector<ll>>;
    const int MOD = 1e9 + 7;

    Matrix multiply(const Matrix& A, const Matrix& B, int m) {
        Matrix C(m, vector<ll>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < m; k++) {
                if (!A[i][k]) continue;
                for (int j = 0; j < m; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix A, ll p, int m) {
        Matrix res(m, vector<ll>(m, 0));
        for (int i = 0; i < m; i++) res[i][i] = 1; 
        while (p > 0) {
            if (p & 1) res = multiply(res, A, m);
            A = multiply(A, A, m);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;
        
        int m = r - l + 1;
        
        Matrix T(m, vector<ll>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                T[i][j] = max(0, m - 1 - max(i, j));
            }
        }
        
        ll pairs = (n - 1) / 2;
        
        Matrix T_p = power(T, pairs, m);
        
        vector<ll> v(m, 1);
        vector<ll> v_paired(m, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                v_paired[i] = (v_paired[i] + T_p[i][j] * v[j]) % MOD;
            }
        }
        
        vector<ll> v_final(m, 0);
        
        if ((n - 1) % 2 != 0) {
            ll pre = 0;
            for (int j = 0; j < m; j++) {
                v_final[j] = pre;
                pre = (pre + v_paired[j]) % MOD;
            }
        } else {
            v_final = v_paired;
        }
        
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + v_final[i]) % MOD;
        }
        
        return (2LL * ans) % MOD;
    }
};