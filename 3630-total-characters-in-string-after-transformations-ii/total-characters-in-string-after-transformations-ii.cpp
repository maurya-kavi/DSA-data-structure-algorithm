class Solution {
public:
// using matrix exponentation
using ll=long long;
using Matrix=vector<vector<ll>>;
int mod=1e9+7;

    Matrix matrixMultiply(Matrix &A, Matrix &B){
        Matrix C(26, vector<ll>(26,0));
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                for(int k=0; k<26; k++){
                    C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
                }
            }
        }
        return C;
    }
    Matrix matrixExpo(Matrix base, int expo){
        if(expo==0){
            Matrix I(26,vector<ll>(26,0));
            for(int i=0; i<26; i++) I[i][i]=1;
            return I;
        }

        Matrix half=matrixExpo(base,expo/2);
        Matrix res=matrixMultiply(half,half);
        if(expo%2==1) res=matrixMultiply(res,base);
        return res;
    }

    vector<ll> matrixMultiply2(Matrix &T, vector<ll>&freq){
        vector<ll>res(26,0);

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                res[i]=(res[i]+T[i][j]*freq[j]%mod)%mod;
            }
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<ll>freq(26,0);
        for(char &ch:s) freq[ch-'a']++;

        // final matrix= T ka pow t * reference matrix(nums)
        Matrix T(26, vector<ll>(26,0));
        // fill the T by considering the given S , nums
        for(int i=0; i<26; i++){
            int nextCnt=nums[i];
            for(int j=1; j<=nextCnt; j++){
                T[(i+j)%26][i]++;
            }
        }
        Matrix tT=matrixExpo(T,t); // 26 * 26
        // nums: 1*26
        vector<ll> finalMatrix=matrixMultiply2(tT,freq); // 1*26

        long long ans=0;
        for(int i=0; i<26; i++){
            ans=(ans+finalMatrix[i])%mod;
        }

        return (int)ans;
       
    }
};