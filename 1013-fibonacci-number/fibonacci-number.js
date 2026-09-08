/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if(n<=1) return n;
    let n1=0,n2=1;
    let ans=1;
    for(let i=2; i<=n; i++){
        ans=n1+n2;
        n1=n2;
        n2=ans;
    }
    return ans;
};