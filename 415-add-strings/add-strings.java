class Solution {
    public String addStrings(String num1, String num2) {
        int n1=num1.length();
        int n2=num2.length();
        int d1=0, d2=0, c=0;
        String s="";
        int i=n1-1, j=n2-1;
        while(i>=0 || j>=0){
            if(i>=0) {
                d1=num1.charAt(i)-'0';
            }
            if(j>=0){
                d2=num2.charAt(j)-'0';
            }
            int sum=d1+d2+c;
            int d=sum%10;
            c=sum/10;
            s+=(char)(d+'0');
            d1=0;
            d2=0;

            i--; j--;
        }
        if(c>0){
            s+=(char)(c+'0');
            c=0;
        }

        String rev=new StringBuilder(s).reverse().toString();
        return rev;
    }
}