class Solution {
    public String toHex(int num) {
        if(num==0) return "0";

        char[] map={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        StringBuilder hexString=new StringBuilder();
        while(num!=0){
            hexString.append(map[num&15]); // get the last 4 bits
            num>>>=4; // unsigned right shift by 4 bits to handle negative numbers correctly

        }

        return hexString.reverse().toString();
    }
}