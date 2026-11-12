class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        int i = 0;
        while (i < n && s.charAt(i) == ' ') i++;

        StringBuilder t = new StringBuilder();
        StringBuilder word = new StringBuilder();

        while (i < n) {
            if (s.charAt(i) == ' ') {
                int l = 0, r = word.length() - 1;
                while (l < r) {
                    char temp = word.charAt(r);
                    word.setCharAt(r, word.charAt(l));
                    word.setCharAt(l, temp);
                    l++;
                    r--;
                }

                t.append(word);
                t.append(" ");
                word = new StringBuilder();

                while (i < n && s.charAt(i) == ' ') i++;
            } else {
                word.append(s.charAt(i));
                i++;
            }
        }
        if(s.charAt(n-1)!=' '){
            int l = 0, r = word.length() - 1;
            while (l < r) {
                char temp = word.charAt(r);
                word.setCharAt(r, word.charAt(l));
                word.setCharAt(l, temp);
                l++;
                r--;
            }
            t.append(word);
        }
        else t.deleteCharAt(t.length() - 1);

        int l = 0, r = t.length() - 1;
        while (l < r) {
            char temp = t.charAt(r);
            t.setCharAt(r, t.charAt(l));
            t.setCharAt(l, temp);
            l++;
            r--;
        }

        return t.toString();
    }
}