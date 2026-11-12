class Solution {
    public int countPrimes(int n) {
        boolean[] precomputePrimes=new boolean[n+1];
        Arrays.fill(precomputePrimes,true);
        if(n>0) precomputePrimes[0]=false;
        if(n>1) precomputePrimes[1]=false;
    
        for(int i=2; i*i<n; i++){
            if(precomputePrimes[i]){
                for(int j=i*i; j<n; j+=i){
                    precomputePrimes[j]=false;
                }
            }
        }
        int ans=0;
        for(int i=2; i<n; i++){
            if(precomputePrimes[i]) ans++;
        }
        return ans;
    }
}