class Solution {
    public boolean strongPasswordCheckerII(String password) {
        int len=password.length();
        boolean islow=false, isup=false, isdig=false, isSpecial=false;
        for(int i=0; i<len; i++){
            if(Character.isLowerCase(password.charAt(i))) islow=true;
            if(Character.isUpperCase(password.charAt(i))) isup=true;
            if(Character.isDigit(password.charAt(i))) isdig=true;
            if(Character.isLetterOrDigit(password.charAt(i))==false) isSpecial=true;
            if(i>0 && password.charAt(i)==password.charAt(i-1)) return false;
        }

        if(len>=8 && islow && isup && isdig && isSpecial) return true;
        return false;
    }
}