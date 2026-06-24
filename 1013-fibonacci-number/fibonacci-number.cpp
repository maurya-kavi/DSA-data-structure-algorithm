class Solution {
public:
// using matrix exponentiation

using Matrix = vector<vector<int>>;

    Matrix matrixMultiply(Matrix &A, Matrix &B){
        Matrix C(2, vector<int>(2,0));
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                for(int k=0; k<2; k++){
                    C[i][j]=(C[i][j]+ A[i][k]*B[k][j]);
                }
            }
        }
        return C;
    }

    Matrix matrixMultiply2(Matrix &A, Matrix &B){
        Matrix C(2, vector<int>(1,0));
        for(int i=0; i<2; i++){
            for(int j=0; j<1; j++){
                for(int k=0; k<2; k++){
                    C[i][j]=(C[i][j]+ A[i][k]*B[k][j]);
                }
            }
        }
        return C;
    }

    Matrix matrixExpo(Matrix base, int expo){
        if(expo==0){
            Matrix res(2,vector<int>(2,0));
            for(int i=0; i<2; i++) res[i][i]=1;
            return res;
        }

        Matrix half=  matrixExpo(base, expo/2);
        Matrix res=matrixMultiply(half,half);
        if(expo%2==1) res=matrixMultiply(res,base);

        return res;
    }

    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;

        // final matrix= t ka pow (n-1) * helping matrix
        vector<vector<int>>helpingMatrix(2,vector<int>(1,0));
        helpingMatrix[0][0]=1;
        helpingMatrix[1][0]=0;

        Matrix T(2, vector<int>(2,0));
        T[0][0]=1;
        T[0][1]=1;
        T[1][0]=1;
        T[1][1]=0;

        Matrix tMatrix=matrixExpo(T,n-1);

        Matrix nthMatrix=matrixMultiply2(tMatrix,helpingMatrix);

        return nthMatrix[0][0];

    }
};


