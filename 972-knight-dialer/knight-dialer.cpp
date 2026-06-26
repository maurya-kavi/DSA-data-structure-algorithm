class Solution {
public:
// using matrix exponentiation
    const int MOD = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;

    Matrix multiply(Matrix& A, Matrix& B) {
        Matrix C(10, vector<long long>(10, 0));
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < 10; ++j) {
                for(int k = 0; k < 10; ++k) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix matrixPower(Matrix A, int p) {
        Matrix res(10, vector<long long>(10, 0));
        for(int i = 0; i < 10; ++i) res[i][i] = 1;

        while(p > 0) {
            if(p % 2 == 1) res = multiply(res, A);
            A = multiply(A, A);
            p /= 2;
        }
        return res;
    }

    int knightDialer(int n) {
        if (n == 1) return 10;

        Matrix M(10, vector<long long>(10, 0));
        vector<vector<int>> moves = {
            {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
            {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
        };

        for(int i = 0; i < 10; ++i) {
            for(int nxt : moves[i]) {
                M[i][nxt] = 1; 
            }
        }

        Matrix M_n_minus_1 = matrixPower(M, n - 1);

        long long ans = 0;
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < 10; ++j) {
                ans = (ans + M_n_minus_1[i][j]) % MOD;
            }
        }

        return ans;
    }
};