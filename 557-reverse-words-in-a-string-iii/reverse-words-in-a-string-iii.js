/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let chars=s.split('');
    let start=0;
    for(let end=0; end<=chars.length; end++){
        // when we reach a space or the end of the string , reverse the word 
        if(end==chars.length || chars[end]==' '){
            let left=start;
            let right=end-1;

            while(left<=right){
                let temp=chars[left];
                chars[left]=chars[right];
                chars[right]=temp;
                left++;
                right--;
            }
            start=end+1;
        }
        // start=end+1;
    }
    return chars.join('');
};