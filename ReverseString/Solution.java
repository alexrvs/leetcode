public class Solution {
    public String reverseString(String s) {
        StringBuilder str = new StringBuilder(s);
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            char c = str.charAt(l);
            str.setCharAt(l, str.charAt(r));
            str.setCharAt(r, c);
            l++;
            r--;
        }
        return str.toString();
    }
}
