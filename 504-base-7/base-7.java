class Solution {
    public String convertToBase7(int num) {
        if(num==0) return "0";
        boolean negSign=false;
        if(num<0) negSign=true;
        num=Math.abs(num);
        String s="";
        while(num>0){
            int digit=num%7;
            s+=(char)(digit+'0');
            num/=7;
        }
        String rev = new StringBuilder(s).reverse().toString();
        if(negSign) rev='-'+rev;
        return rev;
    }
}