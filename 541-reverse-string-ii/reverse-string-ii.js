/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
    let arr=s.split('');
    for(let i=0; i<arr.length; i+=2*k){
        let left=i;
        let right=Math.min(i+k-1,arr.length-1); // reverse up to k chars or until the end of the array
        while(left<right){
            let temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
    }

    return arr.join('');
};