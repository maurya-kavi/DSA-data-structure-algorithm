/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
    nums.sort((a,b)=>b-a);
    let n=nums.length;
    if(n<=2) return nums[0];
    let cnt=1;
    for(let i=1; i<n; i++){
        if(nums[i]==nums[i-1]) continue;
        else{
            cnt++;
            if(cnt==3) return nums[i];
        }
    }

    return nums[0];

};