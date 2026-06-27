class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {

        int x1=(n-k);
        int x2=(k+n);

        int sum=0;

        x1=max(1,x1);

        for(int i=x1; i<=x2; i++){
            if((i&n)==0) sum+=i;
        }

        return sum;
    }
};

/*
approach...........

n-x <=k 
n-k<=x

x>= (n-k)

second case 
x-n <=k
x<=(k+n)

from there we can get all the possible x
then we do the & ops with the n that is x&n==0 , then cnt++;
return cnt as answer

actually we have to not return the no of x possible which is cnt, we have to return the sum of all possible x 
*/